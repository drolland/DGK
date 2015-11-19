#include <string.h>

#include "dstring.h"
#include "dmemory.h"

char* d_strdup(const char* str){
    int len = strlen(str) + 1;
    char* ret = d_malloc(len * sizeof(char));
    memcpy(ret,str,len);
    return ret;
}
