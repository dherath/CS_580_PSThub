#ifndef LINKED_LIST

#define LINKED_LIST

typedef struct Data{
  int x;
}Data;

typedef struct Node{
  Data val;
  struct Node * next, * prev;
}Node;

typedef struct List{
  struct Node * head, * tail;
  struct Data * (*read) (List*,Data);
  void (*insert)(List*, Data);
  struct List * (*join) (List *, List *);
  struct List * (*seperate) (List*);
  
}List;

List *newLst();
Data getData(Node * c);
Data * readList(List *l, Data d);
void insertList(List *l, Data d);
List *joinList(List *l1, List *l2);
List *seperateList(List *l);


int cycleDetection(List list);

#endif
