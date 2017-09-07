#include <stdio.h>
#include <stdlib.h>

void  foo(int x){
  x++;
  printf("foo output = %d\n",x);
}

void foo2(int * ptr) {
  (*ptr)++;
  printf("foo2 pointer routput = %d\n",(*ptr));
}


int main() {
  /*int x[] = {100,99,98};
  printf("%p\n",x);// prints memory address for the first location

  int * ptr = x; // int pointer
  printf("%p\n",ptr);
  printf("%p\n",ptr+1);//adds 4 bytes
  */
  int nums[]= {1,2,3,4,5};
  int * ptr = nums;
  printf("*ptr = %p\n",*ptr);

  int x = 5;
  foo(x);
  printf(" x = %d\n",x);// C works as pass by value

  // to get over it we use pointers
  int * x_ptr = &x;// when assigning a variable to a apointer-> different for arrays
  foo2(x_ptr);// when passing a pointer to a function that needs a pointer
  printf("x = %d\n",x);

  

  
  return 0;
}
