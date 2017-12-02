#include "bst.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/**
 * COnstructor for Node
 **/
Node * newNode(Data d, Node * parent){
  Node * n = malloc(sizeof(Node));
  n->data = d;
  n->left = NULL;
  n->right = NULL;
  n->parent = parent;
  return n;
}

/**
 * Constructor for a Tree
 **/
Tree * newTree(){
  Tree * t = malloc(sizeof(Tree));
  t->root = NULL;
  return t;
}
