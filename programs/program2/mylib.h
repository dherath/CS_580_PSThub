#include <stdio.h>

int myStrStr(char *haystack,char *needle,char *buffer){
  /* int needleSize =0;
  char *bufferIndex = buffer;
  for(char *tempNeedle=needle;*tempNeedle!='\0';tempNeedle++){
    needleSize++;
  }
  printf("needle size =%d\n",needleSize);
  */
  char *bufferIndex=buffer;
  
  for(char * i = haystack;*i!='\0';i++){
    char * temp1 = i;
    char * temp2 = needle;
    buffer = bufferIndex;
    //    int tempSize =0;
    int count = 0;
    while(*temp2!='\0'){
      if(*temp1==*temp2)/* && count<needleSize)*/{
	//*(buffer+count)=*temp1;
	*buffer=*temp1;
	printf("charachter = %c buffer value = %c\n",*temp1,*buffer);
	temp1++;
	temp2++;
	//count++;
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
