#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Name - Jerome DInal Herath
// B no - B00708543
// not working

struct Data{
  int i;
  char *name;
  void (*delete) (struct Data *);
}Data;

struct Data * newData(char * c){
  Data *d = malloc(sizeof(Data));
  strcpy(d->name,c);
  d->delete = deleteData;
  return d;
}

void deleteData(Data *d){
  free(d->delete);
  free(d->name);
  free(d);
}

int main(){
  Data d1 = newData("name");
  d1->delete(d1);
  return 0;
}
