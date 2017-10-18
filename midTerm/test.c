
//char *s ;
//int x;
int main(){
    int * ptr = malloc(sizeof(int));
    ptr = malloc(sizeof(char));
    ptr = malloc(sizeof(char));
    free(ptr);//this only frees the most recent memory allocation
    return 0;
}