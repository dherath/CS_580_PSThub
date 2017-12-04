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
  t->clone = cloneTree;
  t->compare = compareTree;
  t->removeData = removeTree;

  t->traversal=inOrderTraversal;
  
  return t;
}

//----------------------------------------------

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

/**
 *clones a tree
 *@param bst, the pointer to existing tree
 *@return pointer to cloned tree
 **/
Tree * cloneTree(Tree * bst){
  if(bst->root == NULL){
    return NULL;
  }
  Node * n = bst->root;
  Tree * new_tree = newTree();
  preOrderClone(n,new_tree);
  return new_tree;
}

/**
 *helper function: preorder traversal for clone
 *@param n, the pointer to node(original tree)
 *@param new_bst, pointer to new Tree
 **/
void preOrderClone(Node * n, Tree * new_bst){
  if(n== NULL){
    return;
  }
  new_bst->insert(new_bst,n->data);
  preOrderClone(n->left,new_bst);
  preOrderClone(n->right,new_bst);
}

/**
 *compares two trees
 *@param bst, tree1
 *@param new_bst, tree2
 *@return 1 if equal, 0 else
 **/
int compareTree(Tree * bst, Tree * new_bst){
  if(bst == NULL && new_bst == NULL){
    return 1;
  }else if(bst == NULL || new_bst == NULL){
    return 0;
  }
  /*int index = preOrderCompare(bst->root,new_bst->root,0);
   fprintf(stderr,"preOrdercompare : %d\n",index);
  if(index == 0){
    return 1;
  }
  return 0;*/
  Node * n1 = bst->root;
  Node * n2 = new_bst->root;
  int val = 0;
  preOrderCompare(n1,n2,&val);
   fprintf(stderr,"preOrdercompare : %d\n",val);
   if(val == 0){
     //free(val);
     return 1;
   }
   //free(val);
   return 0;
}

/**
 *preOrder helper function : compare
 *@param n1, node 1
 *@param n2, node 2
 *@param value, int flag value
 **/
void preOrderCompare(Node * n1, Node * n2, int * value){
  if(n1==NULL && n2==NULL){
    return;
  }else if(n1==NULL || n2==NULL){
    *value = 1;
    return;
  }
  fprintf(stderr,"n1: %d n2: %d prCmp :%d \n",n1->data.value,n2->data.value,*value);
  if(n1->data.value != n2->data.value){
    *value = 1;
  }
  preOrderCompare(n1->left,n2->left,value);
  preOrderCompare(n1->right,n2->right,value);
}



/**
 *removes a da from a tree
 *@param bst, the pointer to the tree
 *@param value, the data value
 **/
void removeTree(Tree * bst, Data value){
  Node * toDelete = searchNode(bst,value);
  
  if(toDelete != NULL){
    fprintf(stderr,"data value: %d\n",toDelete->data.value);
    if(toDelete->left==NULL && toDelete->right==NULL){
      //inOrderTraversal(bst->root);
      fprintf(stderr,"case 1\n");
      removeLeaf(bst,toDelete); // leaf node
      //inOrderTraversal(bst->root);
    }else if(toDelete->left==NULL || toDelete->right==NULL){
      //inOrderTraversal(bst->root);
      fprintf(stderr,"case 2\n");
      shortCircuit(bst,toDelete);// has one child
      //inOrderTraversal(bst->root);
    }else{
      //inOrderTraversal(bst->root);
      fprintf(stderr,"case 3\n");
      promotion(bst,toDelete);// has two children
      //inOrderTraversal(bst->root);
    }    
  }
}


/**
 *searches for a Node in tree
 *@param bst, the pointer to a tree
 *@param value, the Data value
 *@return pointer to found ode
 **/
Node * searchNode(Tree * bst, Data value){
  if(bst->root == NULL){
    return NULL;
  }
  return searchNodeHelper(bst->root,value);
}

/**
 *searches for Node recursively
 *@param n, the node
 *@param d, the data
 *@return the pointer to Node 
 **/
Node * searchNodeHelper(Node * n, Data d){
  if(n->data.value == d.value){
    return n;
  }else if(n->data.value < d.value){
    if(n->right == NULL){
      return NULL;
    }else{
      return searchNodeHelper(n->right,d);
    }
  }else if(n->data.value > d.value){
    if(n->left == NULL){
      return NULL;
    }else{
      return searchNodeHelper(n->left,d);
    }
  }  
}

/**
 *delete case 1: leaf node
 *@param bst, the tree
 *@param n,the leaf node
 **/
void removeLeaf(Tree * bst, Node * n){
  //return;
  if(n == bst->root){
    bst->root = NULL;
  }else if(n == n->parent->left){
    n->parent->left = NULL;
    n->parent = NULL;
  }else{
    n->parent->right = NULL;
    n->parent = NULL;
  }
  freeNode(n);
  //return bst;
}

/**
 *delete case 2: has one child
 *@param bst, the tree
 *@param n, the node 
 **/
void shortCircuit(Tree * bst,Node * n){

}

/**
 *delete case 3: has two children
 *@param bst, the tree
 *@param n the node
 **/
void promotion(Tree * bst, Node * n){

}

/**
 *helper function: to search right min node
 *@param n the pointer to node
 *@return the pointer to Node found
 **/
Node * searchRightMin( Node * n){
  n = n->right ;
  while(n->left !=NULL){
    n = n->left;
  }
  return n;
}


/**
 *frees the memory of a Node
 *@param the pointer to a Node
 **/
void freeNode(Node * n){
  //free(&(n->data));
  //free(n->left);
  //free(n->right);
  //free(n->parent);
  //&(n->data) = NULL;
  //freeData(n->data);
  free(n->left);
  free(n->right);
  free(n->parent);
  free(n);
}

void inOrderTraversal(Node * n){
  if(n==NULL){
    return;
  }
  inOrderTraversal(n->left);
  fprintf(stderr,"%d\n",n->data.value);
  inOrderTraversal(n->right);
}

