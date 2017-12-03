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
}Tree;

//----- functions------------------

//------ for Node -----------------

Node * newNode(Data d, Node * parent);
Data * insertNode(Node * n, Data d);
Data * readNode(Node * n, Data d);

//----- for Tree ------------------

Tree * newTree();
Data * insertTree(Tree * bst, Data value);
void sortTree(Tree * bst, Data * array);
Data * searchTree(Tree * bst, Data value); 

//----- helper functions-----------

int inOrder(Node * n, Data * array, int index);
  
#endif
