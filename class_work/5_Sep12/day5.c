#include <stdio.h>
#include <stdlib.h>


void swap(int *x, int *y){
  /*int temp = *x;
   *x = *y;
   *y = temp;*/
  // can swap without a thrd variable
  // a bit level swap
  if(*x!=*y){
    *x = *x^*y;
    *y = *x^*y;
    *x^=*x^*y; 
  }
  // cant swap the same thing
  
}

int main() {
  char  x[]="hello";
  char * y= x;
  printf("*y = %p\n",y);
  y[0]='J';
  printf("*y = %p\n",y);
  // this still prints the same memory address

  printf("*(x+1) = %c\n",*(x+1));
  printf("x[1] = %c\n",x[1]);
  //---------------------
  char * d = x;
  int * p = (int *) x;
  printf("d = %p, p = %p \n",d,p);
  printf("d+1 = %p, p+1, = %p \n",++d,++p);//needs to have pre-increment
  // this is the reason we need to have types for pointers
  //---------------------
  for(char * d=x; *d !='\0';d++){
    // can use ++d also,d++ is one extra line in assemblly only
    // loops until a char is not a null charachter, at end of any word we havea  null char
    printf("%c",*d);
  }
  printf("\n");
  //---------------------
  int k[]={1,2,3,4,5};
  for(int * m = k;*m != *k+(sizeof(k)/sizeof(int));++m){
    //segfault
    printf("%d",*m);
  }
  printf("\n");
  
  return 0;
}
