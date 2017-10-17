#include <stdio.h>
#include <string.h>

int main(){
  fprintf(stdout,"first");
  fprintf(stderr,"second");
  //stderr isnt buffered, it runs first
  fprintf(stdout,"first\n");
  fprintf(stderr,"second\n");
  //prints output in corret after adding line breaks
  

  
  char c = ' ';
  while(c !='n'){
    fprintf(stdout,"do you want to continue(press y for yes, n for no):");
    fflush(stdout);
    c = getchar();
    while(getchar() !='\n');
  }

  fprintf(stdout,"enter username: ");
  fflush(stdout);
  char name[255]={0};//initialization
  fgets(name,255,stdin);

  fprintf(stdout,"enter numbe(1-10): ");
  fflush(stdout);
  int number =0;
  fscanf(stdin,"%d",&number);//needs to be the memory address

  // prnt number
  printf("%d\n",number);
  printf("length fo name = %d\n",strlen(name));
  // getting segmentation fault
  /*while(*(name+1) !='\0'){
     *name = *name >> number ;
     name++;
  }

  FILE * fptr = fopen("username.key","w");
  fprintf(fptr,name);
  */
  
}
