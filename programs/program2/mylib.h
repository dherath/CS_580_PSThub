#include <stdio.h>

int myStrStr(char *haystack,char *needle,char *buffer){
  for(char * i = haystack;*i!='\0';i++){
    char * temp1 = i;
    /*for(char *j = needle;*(j+1)!='\0';j++){
      if(*j== *temp1){
	printf("%c\n",*temp1);
	temp1++;
	j++;
      }
      }*/
    char * temp2 = needle;
    while(*(temp2+1)!='\0'){
      if(*temp1==*temp2){
	printf("%c\n",*temp1);
	temp1++;
	temp2++;
      }else{
	break;
      }      
    }
  }
  return 0;
}
