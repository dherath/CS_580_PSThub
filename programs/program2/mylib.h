

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
 * in the binary representation of int x
 */
unsigned int countOnes(int x){
  unsigned int val=0;
  int input = x;
  while(x!=0){
    if(x%2==1){
      val++;
    }
    x = x/2;
  }
  if(input<0){
    val = 32-val;
  }
  return val;
}
