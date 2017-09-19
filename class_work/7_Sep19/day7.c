#include <stdio.h>
#include <stdlib.h>


int main() {
  int num =8;
  int x = 8 & -1;
  int y = num | 0;
  int z = num ^ 0;
  printf("num =%d &-1 = %d or 0 =%d xor =%d\n",num,x,y,z);
  //------------------
  int num2 = 7;
  printf("intitally - num %d, num2 %d\n",num,num2);
  num= num ^num2;
  num2 = num^num2;
  num = num^num2;
  printf("after swap - num %d, num2 %d\n",num,num2);
  //might not work for same number-> but it does :O
  // ~num-> flips the bits
  printf("shift one bit of %d ->%d\n",num2,num2>>1);
  printf("left shift by 1 of %d->%d\n",num2,num2<<1);
  //----------
  return 0;
}
