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

Data getData(Node * c){
  return c->val;
}

List * joinList(List *l1, List* l2){
  if (l1->head==NULL) return l2;
  if (l2->head==NULL) return l1;
  l1-> tail -> next = l2 ->head;
  l2-> head -> previous = l1 -> tail;
  l1-> tail = l2-> tail;
  return l1;
}

List ** seperateList(List *list){
  List * elist= malloc(sizeof(List));
  List * olist= malloc(sizeof(List));
  for(int i=0, Node *c = list->head; c!=NULL;i++,c=c->next){
    //multiple for loops
    if (i%2==0){
      elist -> insert(elist,c->getData());
    }else{
      olist -> insert(olist,c->getData());
    }    
  }
  List ** lists = malloc(sizeof(List*)*2);
  lists[0] = elist;
  lists[1] = olist;

  return lists;

  //----method 2------------
  /*  struct{
    List * l1, *l2;
  }lists ={elist,olist};
  return lists;
  // but then the return type would be ?? void *
  */
  //-----------------------
  
  // how to return two lists
}
