#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 32
//Create a read me of first.txt
int main()
{
    FILE *fp;
    //declare pointer using pointer declaration
    char *buffer = NULL;
    char temp;
    long size;
    //this address will be used to store 
    printf("Address of pointer : %p", buffer);
    fp = fopen("first.txt", "r");

    if(fp == NULL)
    {
        printf("Something is wrong.");
        fclose(fp);
    }

    printf("File was opened successfully.");
    //fseek(file, offset, SEEK_SET: moves the object pointer to the end of the file)
    fseek(fp, 0, SEEK_END);
    //ftell : returns the current file position of the specified stream with respect to the starting of the file
    //using fseek we should be pointing to the end, and now we can use that as a reference for size of the array 
    //based on the start of the file
    size = ftell(fp);
    printf("Size of file: %ld bytes", size);
    // allocate memory using malloc()
    // how to use malloc: ptr = (cast-type*) malloc(byte-size)
    buffer = (char*)malloc(size);
    fread(buffer, 1, size, fp);
    buffer[size] = '\0';
    printf("File content:\n%s\n", buffer);
    //fseek(file, offset, SEEK_SET: moves the object pointer to beggining of the file)
    //reset to begggining so that we can start reading characters
    fseek(fp, 0, SEEK_SET);
    
    //free memory
    free(buffer);
    return 0; 
}
