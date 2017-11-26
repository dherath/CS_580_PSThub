#ifndef DH_PROFILE_H
#define DH_PROFILE_H

#include "data.h"
#include "vector.h"
#include "list.h"

void profileInsert(Vector * vect, List * list);
void profileRead(Vector * vect, List * list);
void profileRemove(Vector * vect, List * list);

#endif
