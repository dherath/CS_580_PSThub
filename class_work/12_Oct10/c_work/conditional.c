#include <stdio.h>
#include <stdlib.h>

#define X 1
#if X
#define MAN(i,j,k){				\
    if((i)>(j)){				\
      (k)=1;					\
    }						\
  }						
#else
#define MAN(i,j,k)						
#endif

// subject - Conditional Compilation
// Name - jerome Dinal Herath Muhtukumaranage
// b no - B00708543

int main() {
  int i=5, j=5, k=0;
  MAN(++i,j++,k);//i gets incremented to 6 first, then it compares, and afterwards j gets incremented
  //the second MAN() just replaces nothing
  printf("%d, %d, %d\n",i,j,k);
  //----------
  return 0;
}
