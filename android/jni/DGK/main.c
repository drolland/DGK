/* 
 * File:   main.c
 * Author: drolland
 *
 * Created on 31 octobre 2015, 11:48
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <thread_db.h>
#include <signal.h>

#include "dlogger.h"
#include "derror.h"
#include "dimg.h"
#include "dtypes.h"
#include "dgkwindow.h"
#include "dsocket.h"
#include <assert.h>
#include <string.h>

#ifdef __ANDROID__
#include <jni.h>
#include <android/sensor.h>
#include <android/log.h>
#include <android_native_app_glue.h>
#endif




/*
 * 
 */

pthread_cond_t condition;

void *threadfunc(void *parm) {
    int rc;

    pthread_mutex_t mutex;
    pthread_mutex_init(&mutex, NULL);

    rc = pthread_mutex_lock(&mutex);


    printf("Thread blocked\n");
    rc = pthread_cond_wait(&condition, &mutex);
    printf("Thread unblocked");



    pthread_mutex_unlock(&mutex);
}

int main(int argc, char** argv) {



    DError* error = NULL;
    DLoggerGroup* default_loger = d_logger_get_default_logger();
    
    DLoggerNetwork* network_logger = d_logger_network_new(0,"192.168.1.70",6666,&error);
    if ( error ){
        DLOG_ERR_E(error,"Can't create NetworkLogger");
        d_error_free(error);
    }
    else{
       d_logger_group_add_logger(default_loger,(DLogger*)network_logger);
    }
    
    
    error = NULL;
    DImg* image = dimg_load_from_bmp_file("test.bmp", &error);

    if (error != NULL) {
        DLOG_ERR_C(error, "could not load image %s", "test.bmp");
        d_error_free(error);
    }


    clock_t start = clock();
    DImg* image2 = dimg_resize(image, 512, 512);
    clock_t stop = clock();
    float seconds = (float) (stop - start) / CLOCKS_PER_SEC * 1000.0f;
    DLOGI("Resize took %f ms", seconds);

    error = NULL;
    DGK_Window* window = dgk_window_create("Hello World", 100, 100, 512, 512, &error);

    if (error) {
        DLOG_ERR_F(error, "DGK_Window creation failed");
        d_error_free(error);
        goto error;

    }

    
    //dgk_window_blit_image(window,image2,0,0);
    //dgk_window_blit_image(window,image2,600,0);



    /*
         struct timespec start;
        timespec_get(&start,TIME_UTC);
    
    
        struct timespec stop;
        timespec_get(&stop,TIME_UTC);
        printf("\ntime %f\n",(stop.tv_nsec - start.tv_nsec)/(1000000.0f));
     */

    /* TimeSpec*/

    /*
        printf("%ld , %ld\n",start.tv_sec,start.tv_nsec);
     */

    /*
    
    
      
   
        pthread_cond_init(&condition,NULL);
    
    
        pthread_mutex_t mutex;
        pthread_mutex_init(&mutex,NULL);

    
        pthread_mutex_lock(&mutex);
        printf("%d : ",pthread_cond_timedwait(&condition,&mutex,&sleep_duration));
    
        perror("Error occured ? : ");
    
    
    
        pthread_t the_thread;
        pthread_create(&the_thread,NULL,threadfunc,NULL);
     */


    //nanosleep(&sleep_duration,NULL);

    struct timespec sleep_duration;
    sleep_duration.tv_sec = 5;
    sleep_duration.tv_nsec = 100000;
    nanosleep(&sleep_duration, NULL);
    
    

error:
    
    if (window) dgk_window_free(window);
    if (image) dimg_free(image);
    if (image2) dimg_free(image2);
    return EXIT_FAILURE;
}


#ifdef __ANDROID__
void android_main(struct android_app* state) {
    //main(0,NULL);
}
#endif