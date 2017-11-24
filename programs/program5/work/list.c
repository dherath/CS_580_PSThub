#include "list.h"
#include "data.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Constructor
 **/
List * newList(){
  List * l = malloc(sizeof(List));

  l->head = NULL;
  l->tail = NULL;

  l->insert = insertList;
  l->delete = deleteList;
  l->read = readList;
  l->remove = removeList;

  return l;
}


void insertList(List * list, Data d){}

Data * readList(List * list, int inded){}

void removeList(List * list, int index){}

void deleteList(List * list){}
