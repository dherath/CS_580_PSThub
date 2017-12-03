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
  t->sort = sortTree;
  t->search = searchTree;
  
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
  if(n->data.value < d.value){
    if(n->right == NULL){
      n->right = newNode(d,n);
      return &(n->right->data);
    }else{
      return insertNode(n->right,d);
    }
  }else if(n->data.value > d.value){
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


/**
 *sorts data in a tree
 *@param bst, the pointer to the tree
 *@param array, a pointer to a data array
 **/
void sortTree(Tree * bst, Data * array){
  //fprintf(stderr,"started function\n");
  Node * n = bst->root;
  int index = 0;
  Data * startptr = array;
  //fprintf(stderr,"in sortTree\n");
  if(n != NULL){
    index = inOrder(n,array,index);
  }
  //array = startptr;
}

/**
 *inorder traversal of tree
 *@param n, the node to traerse
 *@param array, the Data array
 **/
int inOrder(Node * n, Data * array,int index){
  if(n == NULL){
    //index--;
    return index--;
  }
  index = inOrder(n->left,array,index);
  array[index] = n->data;
  //fprintf(stderr,"index: %d data value : %d\n",index,array[index].value);
  index++;
  index = inOrder(n->right,array,index);
}

/**
 *searches for a data value in tree
 *@param bst, the pointer to a tree
 *@param value, the Data value
 *@return pointer to found data object
 **/
Data * searchTree(Tree * bst, Data value){
  if(bst->root == NULL){
    return NULL;
  }
  return readNode(bst->root,value);
}

/**
 *searches for data value recursively
 *@param n, the node
 *@param d, the data
 *@return the pointer to found data
 **/
Data * readNode(Node * n, Data d){
  if(n->data.value == d.value){
    return &(n->data);
  }else if(n->data.value < d.value){
    if(n->right == NULL){
      return NULL;
    }else{
      return readNode(n->right,d);
    }
  }else if(n->data.value > d.value){
    if(n->left == NULL){
      return NULL;
    }else{
      return readNode(n->left,d);
    }
  }  
}
