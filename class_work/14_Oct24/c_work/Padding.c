#include <stdio.h>
#include <stdlib.h>

// Name - Jerome DInal Herath
// B no - B00708543

struct Data{
  int i;
  char word[5];
};

int main(){
  struct Data d ={};
  
  printf("%d\n",sizeof(d));//sizeof prints 8

  struct Data d1={};// after chaange to buffer size->5

  printf("%d\n",sizeof(d1));//size of prints 12
  
  return 0;
}
