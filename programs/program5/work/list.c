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

  l->size = 0;
  l->head = NULL;
  l->tail = NULL;

  l->insert = insertList;
  l->delete = deleteList;
  l->read = readList;
  l->remove = removeList;

  return l;
}

/**
 *Insert function
 *@param list, the pointer to the list
 *@param index, the index to be entered
 *@param value, the data value to be entered
 **/
void insertList(List * list,int index, Data value){
  Node * n = newNode(value); // creates a new node with 'value'
  if(list->head == NULL){
    list->head = list->tail = n;
  }else if(index== list->size){
    Node * n = newNode(value);
    list->tail->next = n;
    n->prev = list->tail;
    list->tail = n;
  }else if(list->size < index){
    n->prev = list->tail;
    list->tail->next = n;
    list->tail = n;
  }else{
    int count = 0;
    Node * current = list->head;
    while(count < index){
      current = current->next;
      count++;
    }
    n->next = current->next;
    current->next->prev = n;
    n->prev = current;
    current->next = n;
  }
  list->size++;
}

/**
 *read function for linked list
 *@param list, the pointer to the list
 *@param index, the index to read
 *@return the pointer to the Data
 **/
Data * readList(List * list, int index){
  if(index < list->size){
    int count = 0;
    Node * current = list->head;
    while(count < index){
      current = current->next;
      count++;
    }
    return &(current->data);
  }
  return NULL;
}

/**
 *removes item for a given index
 *@param list, the pointer to list
 *@param index, the ndex of the node to delete
 **/
void removeList(List * list, int index){
  if(index < list->size && list->head !=NULL && list->tail !=NULL){
    //---------------------
    int count = 0;
    Node * current = list->head;
    // fprintf(stderr,"index : %d, size: %d\n",index,list->size);
    while(count < index){
      current = current->next;
      count++;
    }
    //fprintf(stderr,"found node @ index: %d %d current size: %d\n",count,index,list->size);
    //fprintf(stderr,"count : %d, index: %d\n",count,index);
    //---------------------
    list->size--;
    if(list->size == 0 && count==index){
      list->head = NULL;
      list->tail = NULL;
      //freeNode(list->head);
      //freeNode(current);
    }else if(current == list->head){
      list->head = current->next;
      current->next->prev = NULL;
      current->next = NULL;
      //freeNode(current);
    }else if(current == list->tail){
      list->tail = current->prev;
      current->prev->next = NULL;
      current->prev = NULL;
      //freeNode(current);
    }else{
      current->prev->next = current->next;
      current->next->prev = current->prev;
      current->prev = NULL;
      current->next = NULL;
      //freeNode(current);
    }
    freeNode(current);
  }
}

void deleteList(List * list){
  if(list->head != NULL){
    Node * current = list->tail;
    while(current != list->head){
      current = current->prev;
      freeNode(current->next);
    }
    freeNode(current);
    //free(list);
  }
  free(list->head);
  free(list->tail);
  free(list);
}


//------helper functions-----------

/**
 *Constructor for a new node
 **/
Node * newNode(Data d){
  Node * new_node = malloc(sizeof(Node));
  new_node -> next = NULL;
  new_node -> prev = NULL;
  new_node -> data = d;
  return new_node;
}

/**
 *frees memory for a node
 *@param n, the pointer to a node
 **/
void freeNode(Node * n){
  free(n->next);
  free(n->prev);
  free(&(n->data));
  //free(n);
}
