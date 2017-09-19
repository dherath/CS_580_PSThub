#include <stdio.h>

/*
 * The function myStrStr finds a substring within a a string and 
 * returns 1 if true and 0 if false. The substring is stored in
 * buffer if found
 */
int myStrStr(char *haystack,char *needle,char *buffer){

  char *bufferIndex=buffer;// to remember buffer start memory location  
  for(char * i = haystack;*i!='\0';i++){    
    char * temp1 = i;
    char * temp2 = needle;
    buffer = bufferIndex;    
    while(*temp2!='\0'){
      // starts comparison operation
      if(*temp1==*temp2){
	*buffer=*temp1;
	temp1++;
	temp2++;
	buffer++;
	if(*temp2=='\0'){
	  *buffer = '\0';
	  return 1;
	}
      }else{
	break;
      }      
    }    
  }  
  return 0;
}

/*
 * The funciton retruns the number of ones 
 * in the binary representation of int num
 */
unsigned int countOnes(int num){
  unsigned int val=0;
  int input = num;
  while(num!=0){
    if(num%2==1){
      val++;
    }
    num =num/2;
  }
  if(input<0){
    val = 32-val;
  }
  return val;
}


void binaryArray(int n, int array[], int size){
  for(int i=size-1;i>=0;i--){
    int temp = n;
    temp= temp>>1;
    temp = temp<<1;
    array[i]=n-temp;
    n=n>>1;
  }
}


void binaryPrinter(int array[], int size){
  for(int i=0;i<size;i++){
    printf("%d",array[i]);
  }
  printf("\n");
}
