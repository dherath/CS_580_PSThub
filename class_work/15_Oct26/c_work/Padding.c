#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Name - Jerome DInal Herath
// B no - B00708543

struct Data{
  int i;
  char word[1];//changed buffer size from here
  //double val;
  //char * c;
};

int main(){
  struct Data d ={};
  
  printf("%d\n",sizeof(d));
  //sizeof prints 8 -> for word[1] and no double
  // sizeof prints 12 -> when word[5] and no double
  //sizeof prints 16 -> when word[1] and with double

  return 0;
}
