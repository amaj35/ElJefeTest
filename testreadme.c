#include <stdio.h>
//Create a read me of first.txt
int main()
{
    FILE *fp;

    //pointer stores value in first.txt and writes
    fp = fopen("first.txt", "r");

    //check if file is open
    if(fp == NULL)
    {
        printf("Could not locate file.");
    }
    else
        printf("File read successfully, hurrah!");
        scanf("This is the value %d", &fp);
    
        // Two matrices : Examples below
        // First is 2x3: 2 2
        //               2 2
        //               2 2
        // Next is 3x2:  2 2 2
        //               2 2 2

        //assume these lines are providing two matrices with the given rows and columns and data.
        //Find the multiplication of these two matrices and add the result below the last line in the input file (don't remove its contents).

        // so create two matrices w the given line, not sure which order but I'mma go with 
        int temp = 0;

        for(int i=0; i < 6; i++);
        {
            for(int j= 0; j < 6; j++)
            {
             temp = j; 
             printf("%d", temp);
            }
        }

    return 0;
}
