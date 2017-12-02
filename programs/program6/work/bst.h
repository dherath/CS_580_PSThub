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
}Tree;

//----- functions------------------

//------ for Node -----------------
Node * newNode(Data d, Node * parent);

//----- for Tree ------------------

Tree * newTree();
  
#endif
