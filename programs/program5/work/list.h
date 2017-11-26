#ifndef DH_LIST_H
#define DH_LIST_H 

#include "data.h"

#pragma pack(1)

// Name - Jerome Dinal Herath Muthukumarnage
// B no - B00708543


/**
 *struct for a Node
 **/
typedef struct Node{
  struct Data data;
  struct Node * next, * prev;
}Node;

/**
 *struct for a List
 **/
typedef struct List{
  int size;
  struct Node * head, * tail;
  void (* insert)(struct List * list,int index, Data value);
  struct Data * (* read)(struct List * list, int index);
  void (* remove)(struct List * list, int index);
  void (* delete)(struct List * list);
}List;


//-- functions------------

List * newList();
void insertList(List * list,int index, Data data);
Data * readList(List * list, int index);
void removeList(List * list, int index);
void deleteList(List * list);

//---- helper functions--------

Node * newNode();
void freeNode(Node * n);

#endif
