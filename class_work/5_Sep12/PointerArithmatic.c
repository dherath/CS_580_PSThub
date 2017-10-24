#include <stdio.h>
#include <stdlib.h>

// name - Jerome Dinal Herath Muthukumaranage
// B no - B00708543

void addDash(char * c){
  char * k;
  for(char *d = c; *(d+1)!='\0';d++){
    /*if(*(d+1)=='\0'){
      printf("%c",*d);      
    }else{
      printf("%c-",*d);
      }*/
    printf("%c-",*d);
    if(*(d+2)=='\0'){
      k=d+1;
    }

  }
      printf("%c\n",*k);
  // printf("%c",*(c+(sizeof(c)/sizeof(char))));
}

void reverse(int * x, int size){
  //int * temp = x + size;
  /* for(int *t = x+size-1;t != x;t--){
    printf("%d",*t);
  }
  printf("%d\n",*x);*/
  int * end;
  for(end = x+size-1;x < end ; x++,end--){
    int temp = *x;
    *x = *end;
    *end = temp;
  }
}

int main() {
  char x[]="Fall";
  addDash(x);
  int a[] ={1,2,3,4,5,6};
  int sizeOfArray = sizeof(a)/sizeof(int);
  for(int i=0;i<sizeOfArray;i++){
    printf("%d",a[i]);
  }
  printf("\n");
  reverse(a,sizeOfArray);
  for(int i=0;i<sizeOfArray;i++){
    printf("%d",a[i]);
  }
  printf("\n");
  return 0;
}
