#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>

List * newList(){
  List *l =malloc(sizeof(List));
  l->head =l->tail=NULL;
  l->read = readList;
  l->insert = insertList;
  l->join = joinList;
  l->seperate = seperateList;
  return l;
}

Data * readList(List *l, Data d){
  if (l->head == NULL) return NULL;
  Node * iter = l->head;
  while (iter->next != NULL){
    if (iter->val == d){
      return &(iter->val);// retruns the value
    }
    iter = iter -> next;
  }
}

void insertList(List *l, Data d){
  Node * n = malloc(sizeof(Node));
  n-> next = n->prev = NULL;
  n-> val = d;
  if(l->head == NULL){
    l->head = l->tail = n;
  }else{
    n->prev = l->tail;
    l->tail->next = n;
    l->tail =n;
  }
}

List * joinList(List *l1, List* l2){
  if (l1->head==NULL) return l2;
  if (l2->head==NULL) return l1;
  Node * current = l1 -> tail;
  l1-> tail = l2 ->head;
  l2->head = current;
  return l1;
}

List * seperateList(List *l){
  int index = 1;
  if (l->head == NULL) return NULL;
  List * oddl = malloc(sizeof(List));
  while (l->next !=NULL){
    if (index%2==0){
      
    }else{
      
    }
    l=l->next;
  }
  // how to return two lists
}
