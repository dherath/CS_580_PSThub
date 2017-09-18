#include <stdio.h>

int myStrStr(char *haystack,char *needle,char *buffer){

  char *bufferIndex=buffer;
  
  for(char * i = haystack;*i!='\0';i++){
    char * temp1 = i;
    char * temp2 = needle;
    buffer = bufferIndex;
    int count = 0;
    while(*temp2!='\0'){
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
