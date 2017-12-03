#ifndef DH_BST_H
#define  DH_BST_H 

#pragma pack(1)

// Name - Jerome Dinal Herath Muthukumarnage
// B no - B00708543

/**
 * Data struct
 **/
typedef struct Data{
  int value;
}Data;

/**
 * Node Struct
 **/
typedef struct Node{
  struct Node * left, * right, * parent;
  struct Data data;
}Node;

/**
 * BST struct
 **/
typedef struct Tree{
  struct Node * root;
  
  struct Data * (* insert)(struct Tree * bst, Data value);
  void (* sort)(struct Tree * bst, Data * array);
  struct Data * (* search)(struct Tree * bst, Data value);
  struct Tree * (* clone)(struct Tree * bst);
  int (* compare)(struct Tree * bst, struct Tree * new_bst);
  void (*removeData)(struct Tree * bst, Data value);
  
}Tree;

//----- functions------------------

//------ for Node -----------------

Node * newNode(Data d, Node * parent);
Data * insertNode(Node * n, Data d);
Data * readNode(Node * n, Data d);
Node * searchNodeHelper(Node * n, Data d);
void freeNode(Node * n);

//----- for Tree ------------------

Tree * newTree();
Data * insertTree(Tree * bst, Data value);
void sortTree(Tree * bst, Data * array);
Data * searchTree(Tree * bst, Data value);
Tree * cloneTree(Tree * bst);
int compareTree(Tree * bst, Tree * new_bst);
void removeTree(Tree * bst, Data value);

//----- helper functions-----------

int inOrder(Node * n, Data * array, int index);
void preOrderClone(Node * n, Tree * new_bst);
int preOrderCompare(Node * bst_n,Node * new_bst_n,int value);
Node * searchNode(Tree * bst, Data value);
void removeLeaf(Tree * bst, Node * n);
void shortCircuit(Tree * bst, Node * n);
void promotion(Tree * bst, Node * n);
Node * searchRightMin(Node * n);
void freeData(Data d);

//void inOrderTraversal(Node * n);

#endif
