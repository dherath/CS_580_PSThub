#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
/*
int foo(char p[]) {//dont need pass array size
  printf("%d\n",sizeof(p)); //-> this mehtod wont work - have to use foo(char p[],int sizeofChar)
  return 0;// always returns 8 -> 64 bits/8, 
  }*/

int main(){
  double x = 1024;
  double k = 3.0;
  int y = (int) x;

  char z= (char) x;
  int array[] = {1,2,3,4,5};
  
  printf("x = %.1f\n",x);
  printf("y = %d\n",y);
  printf("z = %d\n",z);// if z is printed as a char -> then nothing is shown(null output), if its printed as a number -> 0
  printf("k = %.1f\n",k);
  printf("operator x>k = %d\n",x>k);//true is 1(or anytn else) &  false is 0(only) instead of boolean

  //---------------
  int size = sizeof(array)/sizeof(int);//works only in same scope
  printf("size of array = %d\n",size);

  // C doesnt have string
  char w1[] = {'a','b','c','\0'};
  char word[] = "Hello";
  printf("strings = %s\n",w1);// doesnt work ?
  printf("word = %s\n",word);

  //  foo(word);// shows 8
  
  return 0;
}
