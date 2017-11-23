#include "data.h"

#ifndef DH_VECTOR_H

#define DH_VECTOR_H 

#pragma pack(1)

// Name - Jerome Dinal Herath Muthukumarnage
// B no - B00708543

/**
 *struct for Vector
 **/
typedef struct Vector{
  struct Data * data;
  unsigned int current_size;
  unsigned int max_size;
  void (* insert)(struct Vector * array, int index, Data value);
  Data * (* read)(struct Vector * array, int index);
  void (* remove)(struct Vector * array, int index);
  struct Vector * (* delete)(struct Vector * array);
}Vector;


//-- functions------------

Vector * newVector();
void insertVector(Vector * array, int index, Data value );
Data * readVector(Vector * array, int index);
void removeVector(Vector * array, int index);
Vector * deleteVector(Vector * array);
#endif
