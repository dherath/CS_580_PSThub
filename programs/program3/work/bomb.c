#include <stdlib.h>

void createKey();
void phase(int num);
char * generatePasscode(int num);

void phase_1(){
	char * pass = generatePasscode(1);
	free(pass);
	phase(1);
	//free(pass);
}
void phase_2(){
	char * pass = generatePasscode(2);
	phase(2);
	free(pass);
}
void phase_3(){
	char * pass = generatePasscode(3);
	phase(3);
	free(pass);
}
void phase_4(){
	char * pass = generatePasscode(4);
	phase(4);
	free(pass);
}
void phase_5(){
	char * pass = generatePasscode(5);
	phase(5);
	free(pass);
}
void phase_6(){
	char * pass = generatePasscode(6);
	phase(6);
	createKey();
	free(pass);
}
