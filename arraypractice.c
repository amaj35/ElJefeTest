#include <stdio.h>
#include <stdlib.h>

//prototype
void testPointer(int array);
void printArrayContents(int array[], int arraySize);
void printmy2dArray(int my2darr[][2], int rows, int columns);
//void printmyblank2dArray(int myunsure2darray[][], int rows, int columns);

void printPointerMemory(int array[])
{
    printf("%p ", array);
}

void printArrayContents(int array[], int arraySize)
{
    for(int i=0; i < arraySize; i++)
    {
        printf("%d ", array[i]);
    }
}
//column size in 2D arrays must be specified explicity when you declare the array
// this is because C requires the compiler to know the size of all dimensions of an array at compile time
//row can be left empty when declaring 2d array bcause C allows you to create an array with different row sizes
void printmy2dArray(int my2darr[][2], int rows, int columns)
{
    for(int i=0; i < rows; i++)
    {
        for(int j=0; j < columns; j++)
        {
            printf("%d", my2darr[i][j]);
        }
    }
}
//what if I don't know my row or column yet? Cannot do the following
//One of the indices must be provided or it will not be accepted
//void printmyblank2dArray(int myunsure2darray[][], int rows, int columns)
//another way to do it is to use dynamic allocation 
int freeArray(int array[]){
    
}
//function
int main()
{
    int rows = 2;
    int columns = 3;
    int array[3] = { 1, 2, 3};
    int my2dArray[3][2];
    char value = '1';
    
    //void* is used to avoid compiler warnings about mismatch between the pointer type
    //and the format specifier
    //& is used to reference the adddress of avariable
    printf("Address of rows: %p", (void*)&rows);
    printf("\n");
    printf("%p ", array);
    printPointerMemory(array);
    printf("\n");
    printArrayContents(array, 3);
    printf("\n");

    return 0;

}