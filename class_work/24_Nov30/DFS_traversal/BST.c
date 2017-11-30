#include "BST.h"

//---------- My method --------------------
// n = node->left
Node * findLeftMax(Node * n){
  if(n->right == NULL){
    return n;
  }else{
    return findLeftMax(n->right);
  }
}

//n = node->right
// this is faster-> recursion is always slower
Node * findRightMin(Node * n){
  while(n->left !=NULL){
    n = n->left;
  }
  return n;
}
//---------------------------------
