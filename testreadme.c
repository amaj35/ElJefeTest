#include <stdio.h>
#include <stdlib.h>
// Create a read me of first.txt
//%p is pointers
//%d is for integers
// scanf() reading input from the user or from a file and starting it in variables
// feof() function to read end of file
// fgetc function to read character in a file stream
// fscanf to read a string from the file and then use sscanf to convert the string to an integer.

int main()
{
	FILE *fp;
	char character;
	// pointer stores value in first.txt and writes
	fp = fopen("first.txt", "r");
	int TwoByThree[2][3];
	int ThreeByTwo[3][2];
	int index = 0;
	int value = 0;

	// check if file is open
	if (fgetc(fp) != EOF)
	{
		printf("File read successfully, hurrah!");
		printf("\n");
		// use fscanf and sscanf
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < 3; j++)
			{
				if (fscanf(fp, " %c", &character) == 1 && character >= '1' && character <= '3')
				{
					TwoByThree[i][j] = character - '0';
					index++;
				}
			}
		printf("The value of index is:%d", index);
		fseek(fp, index, SEEK_SET);
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				if (fscanf(fp, " %c", &character) == 1 && character >= '1' && character <= '3')
				{
					ThreeByTwo[i][j] = character - '0';
				}
			}
		}
		printf("\nArray 2x3:\n");
		// display values returned -------- for both arrays
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				printf("%d ", (TwoByThree[i][j]));
			}
			printf("\n");
		}
		printf("\nArray 3x2:\n");
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				//this one is not putting out correct value for some reason
				printf("%d ", ThreeByTwo[i][j]);
			}
			printf("\n");
		}
	}
		// didn't need this afterall 
		// get the size of the row, as it is the only difference between the ThreeByTwo or the TwoByTwo
		// printf("Size of row int in twobythree is: %d", sizeof(TwoByThree[0]));
		// printf("\n");
		// int value2;
		// //int is 4 bytes
		// printf("Size of value: %d", sizeof(value2));
		// printf("\n");
		// // math parth, should result in 6 solutions
		// printf("Size of row int in threebytwo is: %d", sizeof(ThreeByTwo[0]));
		// printf("\n");
		
		int result[2][3];

		printf("\n");
		for(int i=0; i < 2; i++)
		{
			for(int j=0; j <3; j++)
			{
				printf("The current value of TwoByThree is when index j is %d", j);
				printf(": %d", TwoByThree[i][j]);
				printf("\n");
				printf("The current value of ThreeByTwo whem index i is %d", i); 
				printf(": %d", ThreeByTwo[j][i]);
				printf("\n");
				printf("\n");
				result[i][j] = TwoByThree[i][j] * ThreeByTwo[j][i];
			}
		}
		printf("\nResult value is :\n");
		//print result
		for(int i=0; i < 2; i++)
		{
			for(int j=0; j <3; j++)
			{
				printf("%d ", result[i][j]);
			}
		}
		return 0;
}