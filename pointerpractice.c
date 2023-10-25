#include <stdio.h>
#include <stdlib.h>

int main()
{
    int* p;
    int x = 10;
    printf("Address of pointer is: %p", p);
    p = &x;
    printf("\n");
    printf("Address of x is: %p", p);
    printf("\n");
    p = NULL;
    printf("Address of pointer after using null is: %p", p);

    //Okay, refreshed. Lets try something harder
    printf("\n");
    int array[2] = {4, 3};
    int* o = array;
    for(int i=0; i < 2; i++){
        printf(" Value of the array ptr is: %d ", *o);
        printf("\n");
        o++;
    }

    //int array[] = {1, 2, 3, 4, 5, 6, 7, 9, 22};
    //{
    //    for(int i=0; size)
    //}
    //return 0;
}