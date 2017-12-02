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

  t->insert = insertTree;
  
  return t;
}

/**
 *inserts a node into a BST
 *@param  bst, the pointer to the tree
 *@param value, the data value
 *@return the pointer to the entered data node
 **/
Data * insertTree(Tree * bst, Data value){
  if(bst->root == NULL){
    bst->root = newNode(value,NULL);
    return &(bst->root->data);
  }
  Data * temp = insertNode(bst->root,value);  
  return temp;
}

/**
 *recursive function taht inserts a node 
 *@param n, the reference to a node
 *@param d, the data value to be inserted
 *@return the pointer to the data entered
 **/
Data * insertNode(Node * n, Data d){
  if(n->data.value > d.value){
    if(n->right == NULL){
      n->right = newNode(d,n);
      return &(n->right->data);
    }else{
      return insertNode(n->right,d);
    }
  }else if(n->data.value < d.value){
    if(n->left == NULL){
      n->left = newNode(d,n);
      return &(n->left->data);
    }else{
      return insertNode(n->left,d);
    }
  }else{
    return NULL;
  }
}

