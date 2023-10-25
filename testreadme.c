#include <stdio.h>
#include <stdlib.h>

//function prototypes are not necessary but are good practice for early error detection, readability, compiler optimization
// FUNCTION PROTOTYPES
//====================
void allocateColumns(int rows, int columns, int **array);
int readData(int rows, int columns, FILE *t, int **array);
void printData(int array_num, int rows, int columns, int **array);

/// FUNCTIONS
//=====================
void allocateColumns(int rows, int columns, int **array){
	for(int i=0; i < rows; i++){
		//allocate columns here
		array[i] = (int*)malloc(columns * sizeof(int));
		//basically same error check
		if(array[i] == NULL)
		{
			printf("There was an issue allocating memory.");
			exit(1);
		}
	}
}
int readData(int rows, int columns, FILE *t, int **array)
{
	for(int i=0; i < rows; i++)
	{
		for(int j=0; j < columns; j++)
		{
			//reads int content of dynamically allocated array
			//fscanf()!= 1 means that there was no successful read and assign to 1 item
			if(fscanf(t, "%d", &array[i][j]) != 1)
			{
				printf("There was an error adding contents to array.");
				//error indication
				//note: error indication is usually indicated by a non-zero value.
			}
		}
	}
	return 0;
}

void printData(int array_num, int rows, int columns, int **array)
{
	printf("Array # %d :\n", array_num);
	for(int i=0; i < rows; i++)
	{
		for(int j=0; j < columns; j++)
		{
			printf("%d ", array[i][j]);
		}
		printf("\n");
	}

}
void printResult(int row1, int row2, int col1, int col2, int **array1, int** array2){

	printf("\nMultiplying both arrays results in:\n ");
	//finish code here
}
void freeArray(int rows, int **array){
	for(int i=0; i < rows; i++){
		free(array[i]); 
	}
}

int main()
{
	//file object
	FILE *text;
	int rows1, rows2, columns1, columns2, size;

	text = fopen("first.txt", "r");
	//if text is successfully accessed
	if (text){

		printf("File opened successfully!\n");

		//reads the first line from file
		//fscanf(file, 'const char' which conveniently can be intxint the way its written, gets stored in referenced variables)
		if(fscanf(text, "%dx%d %dx%d", &rows1, &columns1, &rows2, &columns2))
		{
			 //dynamically allocate rows, had trouble w these parameters
			 //allocateRows(rows1, &dynamicArray1);
			 //allocateRows(rows2, &dynamicArray2);
				int** dynamicArray1 = (int**) malloc(rows1 * (sizeof(int*)));
				int** dynamicArray2 = (int**) malloc(rows2 * (sizeof(int*)));
				//dynamically allocate columns
				allocateColumns(rows1, columns1, dynamicArray1);
				allocateColumns(rows2, columns2, dynamicArray2);

				//read data
				readData(rows1, columns1, text, dynamicArray1);
				readData(rows2, columns2, text, dynamicArray2);

				//printData
				printData(1, rows1, columns1, dynamicArray1);
				printData(2, rows2, columns2, dynamicArray2);

				//done reading, close the text
				fclose(text);
				//free up dynamically allocated memory to avoid memory leaks 
				freeArray(rows1, dynamicArray1);
				freeArray(rows2, dynamicArray2);
		}
	}
	// text was not successfully accessed
	else
		printf("Error reading file.\n");
		//make sure to close 
		fclose(text);
	return 0;
}