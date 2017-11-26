#include "list.h"
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
  if(index <= list->size){
    list->size--;
    int count = 0;
    if(list->head != NULL && list->tail != NULL){
      Node * current = list->head;
      while(count < index){
	current = current->next;
	count++;
      }
      if(current == list->head && current== list->tail){
	list->head = NULL;
	list->tail = NULL;
      }else if(current == list->head){
	if(current->next == list->tail){
	  list->head = list->tail;
	}else{
	  list->head = current->next;
	}
	current->next->prev = NULL;
	current->next = NULL;
      }else if(current == list->tail){
	if(current->prev == list->head){
	  list->tail = list->head;
	}else{
	  list->tail = current->prev;
	}
	current->prev->next = NULL;
	current->prev = NULL;
      }else{
	current->prev->next = current->next;
	current->next->prev = current->prev;
	current->next = NULL;
	current->prev = NULL;
      }
      freeNode(current);
    }
  }
}

void deleteList(List * list){
  while(list->size > 0){
      list->remove(list,0);
  }
  free(list->head);
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
  free(n);
}
