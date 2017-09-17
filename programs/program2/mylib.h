
int myStrStr(char *haystack,char *needle,char *buffer){
  int size = 0;
  for(char *temp=needle;*temp!='\0';temp++){
    size++;
  }

  for(char *i=haystack;*i!='\0';i++){
    for(char *j=needle;*j!='\0';j++){
      int count = 0;
      if(*j==*(i+count)){
	*(buffer+1)=*i;
	count++;
      }
      if(size==count){
	return 1;
      }
    }
  }
  return 0;
  
}
