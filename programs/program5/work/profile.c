#include "profile.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>


struct timeval start, stop;

void profileInsert(Vector * vect, List * list){
  Data data_set[1000];
  for(int i = 0; i < 1000 ; i++){
    data_set[i].value = i+1;
  }
  //--------- vector insert -------------------
  //struct timeval start, stop;
  gettimeofday(&start,NULL);
  //time_t start_time_v = (start.tv_sec* 1000000) + start.tv_usec;
  for(int i = 0 ;i < 1000 ; i++){
    vect->insert(vect,i,data_set[i]);
  }
  gettimeofday(&stop,NULL);
  time_t start_time_v = (start.tv_sec* 1000000) + start.tv_usec;
  time_t stop_time_v = (stop.tv_sec* 1000000) + stop.tv_usec;
  //fprintf(stderr,"start time:  %f end time: %f\n",start_time_v,stop_time_v);
  float profile_time_v = stop_time_v - start_time_v;
  fprintf(stderr,"\nprofile time for vector insert: %f\n",profile_time_v);
  //---------- list insert --------------------
  gettimeofday(&start,NULL);
  for(int i = 0; i < 1000 ; i++){
    list->insert(list,i,data_set[i]);
  }
  gettimeofday(&stop,NULL);
  time_t start_time_l = (start.tv_sec* 1000000) + start.tv_usec;
  time_t stop_time_l = (stop.tv_sec* 1000000) + stop.tv_usec;
  float profile_time_l = stop_time_l - start_time_l;
  fprintf(stderr,"profile time for list insert: %f\n",profile_time_l);  
}


void profileRead(Vector * vect, List * list){
  
}
