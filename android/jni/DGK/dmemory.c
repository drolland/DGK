#include "dmemory.h"
#include "dtypes.h"
#include <stdio.h>

static boolean g_exit_on_malloc_failure = TRUE;

void* d_malloc(size_t size){
    void* mem = malloc(size);
    if ( mem == NULL){
        printf("DLib:CRITICAL: d_malloc() failed !!!\n");
        if ( g_exit_on_malloc_failure )
            exit(EXIT_FAILURE);
        return NULL;
    }
    return mem;
}

void d_set_malloc_exit_on_failure(boolean b){
    g_exit_on_malloc_failure = b;
}

static void* memory_pool= 0;
static void* memory_pool_next_available_memory = 0;
static int memory_pool_remaining_memory = 0;

#define POOL_SIZE 8192000

void* d_mpool_alloc(size_t size){
    if ( memory_pool == 0){
        memory_pool = d_malloc(POOL_SIZE);
        memory_pool_next_available_memory = memory_pool;
        memory_pool_remaining_memory = POOL_SIZE;
    }
    
    if ( size > memory_pool_remaining_memory){
        printf("Memory pool out of memory");
        exit(EXIT_FAILURE);
    }
    
    void* allocate = memory_pool_next_available_memory;
    memory_pool_remaining_memory -= size;
    memory_pool_next_available_memory += size;
    return allocate;
}

void d_mpool_release(){
    memory_pool_next_available_memory = memory_pool;
    memory_pool_remaining_memory = POOL_SIZE;    
}

void d_mpool_free(){
    free(memory_pool);
}