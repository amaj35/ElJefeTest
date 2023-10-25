#include <stdio.h>
#include <ctype.h> // for isdigit()

#define BUFFER_LIMIT 100

void printArray(int x, int y, int arr[x][y]) {
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

void initializeArray(int x, int y, int arr[][]) {
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            arr[i][j] = 0;
        }
        printf("\n");
    }
}

int main() {
    FILE *text;
    int rows = 0;
    int columns = 0;
    int index = 0;
    char character;
    int array1[2][3];
    int array2[3][3];
    char buffer[BUFFER_LIMIT];

    text = fopen("first.txt", "r");

    if (text) {
        // Initialize arrays to zero
        initializeArray(2, 3, array1);
        initializeArray(3, 2, array2);

        fseek(text, 0, SEEK_SET);
        printf("Hurray, file is open!\n");

        while ((character = fgetc(text)) != EOF) {
            if (isdigit(character)) {
                int value = character - '0';
                if (rows == 0) {
                    rows = value;
                } else if (columns == 0) {
                    columns = value;
                }
            } else if (character == 'x' && rows > 0 && columns > 0) {
                int currentArray[3][2];
                if (rows <= 2 && columns <= 3) {
                    for (int i = 0; i < rows; i++) {
                        for (int j = 0; j < columns; j++) {
                            int val = fgetc(text) - '0';
                            currentArray[i][j] = val;
                        }
                    }
                } else if (rows <= 3 && columns <= 2) {
                    for (int i = 0; i < rows; i++) {
                        for (int j = 0; j < columns; j++) {
                            int val = fgetc(text) - '0';
                            currentArray[i][j] = val;
                        }
                    }
                } else {
                    printf("Invalid dimensions for arrays. Issue issue\n");
                }

                if (rows <= 2 && columns <= 3) {
                    // Copy the values from currentArray to array1
                    for (int i = 0; i < rows; i++) {
                        for (int j = 0; j < columns; j++) {
                            array1[i][j] = currentArray[i][j];
                        }
                    }
                } else if (rows <= 3 && columns <= 2) {
                    // Copy the values from currentArray to array2
                    for (int i = 0; i < rows; i++) {
                        for (int j = 0; j < columns; j++) {
                            array2[i][j] = currentArray[i][j];
                        }
                    }
                }
                
                rows = 0; // Reset rows
                columns = 0; // Reset columns
            }

            if (index < BUFFER_LIMIT) {
                buffer[index] = character;
                index++;
            }
        }

        fclose(text);
        printf("Array 1:\n");
        printArray(2, 3, array1);
        printf("Array 2:\n");
        printArray(3, 2, array2);
    } else {
        printf("Issue with the text.\n");
    }

    return 0;
}
