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
    //Data * new_dataArray = malloc(array->max_size*sizeof(Data));
    Data * new_dataArray = calloc(array->max_size,array->max_size*sizeof(Data));
    memcpy(new_dataArray,array->data,array->current_size*sizeof(Data));
    free(array->data);
    array->data = new_dataArray;
  }
  if(array->current_size <= index+1){
    array->current_size = index + 1;
  }
  array->data[index] = value;
}

/**
 *read function
 *@param array, the pointer to the vector
 *@param index, the index to the value
 *@return the pointer to the data
 **/
Data * readVector(Vector * array, int index){ 
  if(index < array->current_size){
    if(array->data[index].value==0){
      array->data[index].value = -1;
    }
    return &(array->data[index]);
  }
  return NULL;
}

/**
 *removed element from vector
 *@param array, the pointer to the vector
 *@param index, the index to the value
 **/
void removeVector(Vector * array, int index){
  Data * temp = readVector(array,index);
  if(temp!=NULL){
    for(int i=index ; i< array->max_size-1;i++){
      array->data[i] = array->data[i+1];
    }
    int new_max_size = array->max_size-1;
    int new_current_size = array->current_size-1;
    array->current_size = new_current_size;
    array->max_size = new_current_size;
  }
  //free(&(array->data[array->max_size]));
  //free(&temp);
}

void deleteVector(Vector * array){
  free(array->data);
  free(array);
}
