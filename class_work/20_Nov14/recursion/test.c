#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Name - Jerome Dinal herath Muthukumaranage
// B No - B00708543


int recurs(int val){
  if(val>0){
    printf("%d\n",val);
    val--;
    return recurs(val);
  }else if(val<0){
    printf("%d\n",val);
    val++;
    return recurs(val);
  }else if(val==0){
    printf("%d\n",val);
    return 0;
  }
}
// can use (val>0) ? recurs(val-1) : recurs(val+1);


int main(){

  printf("for -10 ->\n");
  recurs(-10);
  printf("----------\n");
  printf("for +10 ->\n");
  recurs(10);
  return 0;
}
