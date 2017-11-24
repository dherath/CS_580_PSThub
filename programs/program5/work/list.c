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
  if(index <= list->size){
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

void removeList(List * list, int index){}

void deleteList(List * list){}


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
