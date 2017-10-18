#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *file;

    file = fopen("name.txt", "rt");
    if (file == NULL)
    {
        printf ("Error - Couldn't open file\n");
        return (-1);
    }

    fseek(file, 0, SEEK_END); // move file pointer to end of file
    long size = ftell(file); // file pointer position == character count in file
    fseek(file, 0, SEEK_SET);  // move back to beginning of file

    char* buffer = malloc(size * sizeof(char));

    fread(buffer, sizeof(char), size, file); // read file contents to buffer
    char temp;
    for(long i = 0; i < size/2; ++i)
    {
        temp = buffer[i];
        buffer[i] = buffer[size-i-1];
        buffer[size-i-1] = temp;
    }

    fseek(file, 0, SEEK_SET); // The fread set the file pointer to the end so we need to put it to the front again.
    printf("%s\n",buffer);
    fwrite(buffer, sizeof(char), size, file); // Write reverted content

    //free(buffer);
    fclose (file);
}