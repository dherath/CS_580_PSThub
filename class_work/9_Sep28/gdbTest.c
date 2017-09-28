#include <stdio.h>
#include <stdlib.h>

void fooA(){
  char str[]= "fooA";
  fooB();
}

void fooB(){
  char str[]= "fooB";
  barA();
}

void barA(){
  char str[]= "barA";
  barB();
}

void barB(){
  char str[]= "barB";
}

int main() {
  fooA();
  //----------
  return 0;
}
