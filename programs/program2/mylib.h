
int myStrStr(char *haystack,char *needle,char *buffer){
  int size =0;
  for(char *temp=needle;*temp!='\0';temp++){
    size++;
  }
  
  while(*haystack != *needle){
    haystack++;
    if(*haystack=='\0'){
      return 0;
    }
  }

  for(char *i=haystack;*i!='\0';i++){
    char *j = needle;
    char *k = i;
    int count = 0;
    while (*j==*k && count<size){
      j++;
      *(buffer+count)=*k;
      k++;
      count++;
    }
    if(count==size-1){
      return 1;
    }
  }
  return 0;
}
