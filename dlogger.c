#include <stdio.h>
#include <assert.h>
#include <stdarg.h>
#include <string.h>
#include "dlogger.h"
#include "derror.h"
#include "dmemory.h"
#include "dtypes.h"
#include "dlist.h"

enum {
    LOGGER_TYPE_CONSOLE,
    LOGGER_TYPE_GROUP    
};

typedef struct _d_logger {
    void (*log)(DLogger* logger,int log_level,char* msg,va_list vl);
    int log_level;
    int logger_type;
} DLogger;

typedef struct _d_logger_console{
    DLogger logger;
} DLoggerConsole;

typedef struct _d_logger_group{
    DLogger logger;
    DSList* children;
} DLoggerGroup;

static DLoggerGroup* g_default_logger = NULL;


char* build_message(int log_level,char* msg){
    char* str = d_malloc(sizeof(char)*strlen(msg) + 32 * sizeof(char));
    
    switch(log_level){
         case LOGLEVEL_DEBUG:
            sprintf(str,"DEBUG   : %s",msg);
            break;
        case LOGLEVEL_VERBOSE:
            sprintf(str,"VERBOSE : %s",msg);
            break;
        case LOGLEVEL_INFO:
            sprintf(str,"INFO    : %s",msg);
            break;
        case LOGLEVEL_WARNING:
            sprintf(str,"\e[34mWARNING : %s\e[0m",msg);
            break;
        case LOGLEVEL_ERROR:
            sprintf(str,"\e[31mERROR   : %s\e[0m",msg);
            break;
        case LOGLEVEL_CRITICAL:
            sprintf(str,"\e[1;4;31mCRITICAL: %s\e[0m",msg);
            break;
        case LOGLEVEL_FATAL:
            sprintf(str,"\e[1;4;5;31mFATAL   : %s\e[0m",msg);
            break;
        default:
            break;
    }
    
    return str;    
}


/* Logging function for DLoggerConsole*/
void log_console(DLogger* logger,int log_level,char *msg, va_list vl){
    if ( log_level >= logger->log_level ){
    char* str = build_message(log_level,msg);
    vprintf(str,vl);    
    printf("\n");
    free(str);
    }
}

void log_group(DLogger* logger,int log_level,char *msg, va_list vl){
    
    DLoggerGroup* logger_group = (DLoggerGroup*)logger;
    DSList* iter = logger_group->children;
    
    while(iter!=NULL){
        DLogger* l = iter->content;
        l->log(l,log_level,msg,vl);
        iter = iter->next;
    }

}

DLoggerConsole* d_logger_console_new(int log_level){
    DLoggerConsole* new_logger_console = d_malloc(sizeof(DLoggerConsole));
    new_logger_console->logger.log_level = log_level;
    new_logger_console->logger.log = log_console; 
    new_logger_console->logger.logger_type = LOGGER_TYPE_CONSOLE;
    return new_logger_console;
}

DLoggerGroup* d_logger_group_new(){
    DLoggerGroup* new_logger_group = d_malloc(sizeof(DLoggerGroup));
    new_logger_group->logger.log_level = LOGLEVEL_VERBOSE;
    new_logger_group->logger.log = log_group;
    new_logger_group->logger.logger_type = LOGGER_TYPE_GROUP;
    new_logger_group->children = NULL;
    return new_logger_group;
}

void d_logger_free(DLogger* logger){
    switch(logger->logger_type){
        case LOGGER_TYPE_CONSOLE:
            free(logger);
            break;
        case LOGGER_TYPE_GROUP:;
            DLoggerGroup* logger = logger;
            DSList* iter = logger->children;
            while(iter!=NULL){
                d_logger_free(iter->content);
                iter = iter->next;
            }
            d_slist_free(logger->children);
            break;
        default:
            assert(FALSE);
    }   
}

void d_logger_set_loglevel(DLogger* logger,int log_level){
    logger->log_level = log_level;
}

void d_logger_group_add_logger(DLoggerGroup* group,DLogger* logger){
    group->children = d_slist_append(group->children,logger);    
}



DLoggerGroup* d_logger_get_default_logger(){
    if ( g_default_logger == NULL){
        g_default_logger = d_logger_group_new();
        DLoggerConsole* console_logger = d_logger_console_new(0);
        d_logger_group_add_logger(g_default_logger,D_LOGGER(console_logger));
    }
    return g_default_logger;
}

void d_log(DLogger* logger,int log_level,char* msg, ... ){
    va_list args;
    va_start(args,msg);
    logger->log(logger,log_level,msg, args);
    va_end(args);
}


void d_log_error(DLogger* logger, DError* error, int log_level,char* msg,...){
    char* buffer;
    
    va_list args;
    va_start(args,msg);
    int count = vsnprintf(buffer,0,msg,args);
    va_end(args);
    int count2 = snprintf(buffer,0," : %s -> In file %s at line %d ",error->msg,error->file,error->line);
    
    buffer = d_malloc(sizeof(char)*(count + count2 + 2));
    
    va_list args2;
    va_start(args2,msg);
    vsnprintf(buffer,count+1,msg,args2);
    va_end(args2);
    snprintf(buffer+count,count2+1," : %s -> In file %s at line %d ",error->msg,error->file,error->line);
   
    d_log(logger,log_level,buffer);
    
    free(buffer);
}