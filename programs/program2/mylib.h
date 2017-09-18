




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
