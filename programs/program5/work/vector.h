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
  
}Vector;


//-- functions------------

Vector * newVector();


#endif
