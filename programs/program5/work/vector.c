#include "vector.h"
#include "data.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 *Constructor for a new vector
 **/
Vector * newVector(){
  Vector * new_v = malloc(sizeof(Vector));

  new_v->data = NULL;
  new_v->current_size = 0;
  new_v->max_size = 0;
  
  new_v->insert = insertVector;
  new_v->read = readVector;
  new_v->remove = removeVector;
  new_v->delete = deleteVector;

  return new_v;
}

/**
 *insert functions
 *@param array, the pointer to the vector
 *@param index, the index to enter value
 *@param value, the value to be entered
 **/
void insertVector(Vector * array, int index, Data value ){
  if(index >= array->max_size){
    array->max_size = index *2 + 1;
    Data * new_dataArray = malloc(array->max_size*sizeof(Data));
    memcpy(new_dataArray,array->data,array->current_size*sizeof(Data));
    free(array->data);
    array->data = new_dataArray;
  }
  if(array->current_size <= index+1){
    array->current_size = index + 1;
  }
  array->data[index] = value;
}

Data * readVector(Vector * array, int index){

  if(array->max_size < index){
    fprintf(stderr,"inside NULL\n");
    return NULL;
  }
  if(array->current_size < index){
    Data * temp = malloc(sizeof(Data));
    temp->value = -1;
    //   fprintf(stderr,"index %d array->current_size %d\n",index,array->current_size);
    return temp;
  }
  // print max size also
  fprintf(stderr,"index %d array->current_size %d\n",index,array->current_size);
  fprintf(stderr,"not inside ifs");
  return &(array->data[index]);
}

void removeVector(Vector * array, int index){}

void deleteVector(Vector * array){}
