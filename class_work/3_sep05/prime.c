#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main() {
  // name - Jerome Dinal Herath Muthukumaranage
  // B no - B00708543
  for(int i=1;i<100;i++){
    int flag = 1;
    for(int j=i-1;j>1;j--){
      if( i%j == 0){
	flag = 0;
	break;
      }
    }
    if (flag) printf("%d\n",i);
  }
  return 0;
}
// do this from a function
