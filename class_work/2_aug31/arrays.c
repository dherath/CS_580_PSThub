#include <stdio.h>

// student name - Jerome Dinal Herath Muthukumaranage
// B no - B00708543

int main(){
  int nums[] = {10,12,13,14,20};
  char name[]= "Spider-Man";
  char secret_name[] = {
    'P','e','t','e','r',' ',
    'P','a','r','k','e','r','\0'
  };

  //------printing------------
  printf("the size of an int: %ld\n",sizeof(int));//4
  printf("the size of nums(in[]): %ld\n",sizeof(nums));//20
  printf("the size of ints in num: %ld\n",sizeof(nums)/sizeof(int));//5
  printf("the first num is %d, the 2nd %d.\n",nums[0],nums[1]);// 10, 12
  printf("the size of a  char: %ld\n",sizeof(char));//1 its in bytes
  printf("the size of name(char[]): %ld\n",sizeof(name));//11 its in bytes
  printf("the number of chars: %d\n",sizeof(name)/sizeof(char));//11 thats with the null byte
  printf("the size of secret_name(char[]): %ld\n",sizeof(secret_name));//13
  printf("the number of chars: %ld\n",sizeof(secret_name)/sizeof(char));//13
  printf("name=\"%s\"and secret_name=\"%s\"\n",name,secret_name);//Spider-Man,Peter Parker
  return 0;
}
