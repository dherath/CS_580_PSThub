#include <stdio.h>
#include <stdlib.h>

// name - Jerome Dinal Herath Muthukumaranage
// B no - B00708543

int main() {
  //use memset
  // ------- part 1--------------------
  //this is bad code !!!
  int *ptr = malloc(sizeof(int));
  // *ptr = 5;// initial value
  printf("values in  memory ->\n");
  for(int i=0;i<4;i++){
    printf("%d\n",*(ptr+i));// unallocated memory for next four integers
  }

  memset(ptr,1,sizeof(int)*4);// sets bytes to 1
  // -> sets 0001 0001 ...
  printf("\nafter memset->\n");
  for(int i=0;i<4;i++){
    printf("address = %p , value = %d \n",ptr+i,*(ptr+i));
  }

  free(ptr);
  return 0;
}
