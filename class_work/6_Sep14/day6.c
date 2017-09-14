#include <stdio.h>
#include <stdlib.h>

/*int * foo(){
  int x=5;
  return &x;//gets a seg fault
  }*/
/*int * foo(){
  // not limited by scope
  int size = sizeof(int)*2;
  int * ptr;
  ptr = malloc(size);
  //ptr =realloc(ptr,sizeof(int))
  //for(int i=0;i<4;i++)
  // ptr[i]=i;// sets only 1 & 2 -> 3,4 are actually out of bounds
   for(int i=0;i<1;i++)
     ptr[i]=i+1; 
  return ptr;
  }*/



int main() {

  //  int * ptr =  foo();
  //printf("%d\n",*ptr);
  //  printf("%s\n",*ptr);

  //int *ptr = malloc(4); // returns address of when 4 bytes start (in heap)
  // malloc automatically casts to whatever type we tell it to
  //better to use sizeof()

  /*int *ptr = malloc(sizeof(int));
  *ptr = 5;
  // for an array ->
  int *ptr1 = malloc(sizeof(int)*5);
  //int * iptr = (int *) ptr;
  printf("%d\n",*ptr);*/
  int * ptr = foo();
  printf("%d\n",ptr[1]);

  //ptr =realloc(ptr,sizeof(int))
  
  return 0;
}
