
#include <string.h>
#include <stdio.h>
#include "derror.h"
#include "dmemory.h"
#include "dlogger.h"
#include <stdarg.h>
#include "dstring.h"

DError* d_error_new(int code, int level,const char* file,int line, const char* msg,...){
    
    char* buffer;
    
    DError* error = (DError*)d_malloc(sizeof(DError));
    error->code = code;
    error->level = level;
    
    if ( msg == NULL){
        error->msg = NULL;
    }
    else {
        error->file = d_strdup(file);
        error->line = line;
        
        va_list args;
        va_start(args,msg);
        int count = vsnprintf(buffer,0,msg,args);
        va_end(args);
        buffer = d_malloc(sizeof(char)*count+1);
        
        va_list args2;
        va_start(args2,msg);
        vsnprintf(buffer,count+1,msg,args2);
        va_end(args2);
        
        error->msg = buffer;
        
    }
    
    return error;
}


void d_error_free(DError* error){
    if ( error->file ) free(error->file);
    if ( error->msg ) free(error->msg);
    free(error);    
}