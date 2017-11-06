#include "vector.h"

Vector  * newVector(){
  Vector *new_v = malloc(sizeof(Vector));
  new_v->delete = deleteVector;
}

Vector *  deleteVector(Vector *v,int index){
  if(v->max_size < index){
    return NULL;
  }
  
  int *new_array = malloc((v->max_size-1)*sizeof(int));
  memcpy(new_array,v->array,index*sizeof(int));
  memcpy(new_array+(index+1));
  //--incomplete ----------

  // use when aceess speed > needed
  
}

void freeVector(Vector *v){
  free(v->array);
  free(v);
}
