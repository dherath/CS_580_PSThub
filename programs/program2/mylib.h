#include <stdio.h>

int myStrStr(char *haystack,char *needle,char *buffer){
  for(char * i = haystack;*i!='\0';i++){
    char * temp1 = i;
    for(char *j = needle;*j!='\0';j++){
      if(*temp1 == *j){
	printf("%c",*temp1);
	temp1++;
	j++;
      }
    }
  }
  return 0;
}
