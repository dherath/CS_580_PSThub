#ifndef VECTOR_H

#define VECTOR_H

typedef struct Vector{
  int current_size, max_size;
  int * array;
  struct Vector * (*delete) (Vector *, int);
  void (*free) (Vector *);
}

#endif
