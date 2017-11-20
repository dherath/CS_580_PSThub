#include "vector.h"
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


void insertVector(Vector * array, int index, Data value ){}

Data * readVector(Vector * array, int index){}

void removeVector(Vector * array, int index){}

void deleteVector(Vector * array){}
