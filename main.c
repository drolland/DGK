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

#include "d_logger.h"
#include "d_error.h"
#include "d_img.h"
#include "d_types.h"
#include "dgk_window.h"
#include "d_socket.h"
#include "d_ml.h"
#include <assert.h>
#include <string.h>
#include "SDL_main.h"
#include "dgk_shader.h"
#include "dgk_3dobject.h"
#include "d_time.h"

#ifdef __ANDROID__
#include <jni.h>
#include <android/sensor.h>
#include <android/log.h>
//#include <android_native_app_glue.h>
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

int main(int argc, char* argv[]) {

    struct timespec sleep_duration;
    sleep_duration.tv_sec = 1;
    sleep_duration.tv_nsec = 0;
    nanosleep(&sleep_duration, NULL);


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
    DImg* image = NULL;
    image = d_img_load_from_bmp_file("ootest.bmp", &error);

    if (error != NULL) {
        DLOG_ERR_C(error, "could not load image %s", "test.bmp");
        d_error_free(error);
    }


    clock_t start = clock();
     DImg* image2 = NULL;
    if ( image ){
        image2 = d_img_resize(image, 512, 512);
    }
    clock_t stop = clock();
    float seconds = (float) (stop - start) / CLOCKS_PER_SEC * 1000.0f;
    //DLOGI("Resize took %f ms", seconds);
    
    

    
    error = NULL;
    
    
    dgk_window_create("Hello World", 100, 100, 512, 512, &error);

    if (error) {
        DLOG_ERR_F(error, "DGK_Window creation failed");
        d_error_free(error);
        goto error;

    }

    dgk_window_clear_color(0,1,0,0);
    dgk_window_swap();
            
    mat4 mat1 = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
    mat4 mat2 = {0,0,0,0,0,0,0,0,0,0,0,0,10,12,15,1};
    vec3 vec = {0,0,0};
    vec3 vec_res;
    mat4 res;
    
   
    d_mat4_print(mat1);
    d_mat4_mul_mat4(res,mat1,mat1);
    d_mat4_print(res);
    
    d_mat4_mul_vec3(vec_res,mat2,vec);
    printf("%f %f %f\n",vec_res[0],vec_res[1],vec_res[2]);
    
    error = NULL;
    DGKTexture* texture = dgk_texture_load_from_bmp_file("test.bmp",&error);
    if ( error ){
        DLOG_ERR_F(error, "could not load texture %s", "test.bmp");
        d_error_free(error);
        goto error;
    }
        
    
    DGKSprite* sprite = dgk_sprite_new();
    dgk_sprite_set_size(sprite,0.2,0.2);
    //dgk_sprite_set_position(sprite,0.1,0.4);
    dgk_3dobject_set_texture((DGK3DObject*)sprite,texture);
    dgk_3dobject_render((DGK3DObject*)sprite);
    dgk_window_swap();
    
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

    
   
/*
    sleep_duration.tv_sec = 5;
    sleep_duration.tv_nsec = 0;
    nanosleep(&sleep_duration, NULL);
*/
    
    d_nanosleep(5,0);
    
error:
    DLOGI("Exiting...");
    if ( texture ) dgk_texture_free(texture);
    if ( network_logger ) d_logger_free((DLogger*)network_logger);
    if (image) d_img_free(image);
    if (image2) d_img_free(image2);
    exit(EXIT_FAILURE);
}



#ifdef __ANDROID__
/*
void android_main(struct android_app* state){

    //app_dummy();
    
    
    main(0,NULL);
}
*/
#endif
