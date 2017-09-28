#include <stdio.h>
#include <stdlib.h>


void foo(){
  int x = 5;
  char str[]= "Hello World\n";
  printf("%s",str);
}

int main() {
  foo();
  //----------
  return 0;
}
