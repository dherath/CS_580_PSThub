#ifndef DH_BST

#define DH_BST

typedef struct Data{
  int x;
}Data;

typedef struct Node{
  Data val;
  struct Node * left, * right, * parent;
}Node;

typedef struct BST{
  struct Node * root;
}BST;

void insertBST(BST * bst, Data d);
void insertNode(Node * n, Data d);

Node * findLeftMax(Node * n);
Node * findRightMin(Node * n);

#endif
