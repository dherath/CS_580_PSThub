#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main() {
  int x[] = {100,99,98};
  printf("%p\n",x);// prints memory address for the first location

  int * ptr = x; // int pointer
  printf("%p\n",ptr);
  printf("%p\n",ptr+1);//adds 4 bytes
  return 0;
}

