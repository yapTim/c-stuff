#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *findUnique(char[]);

int main()
{
    char array[100];
    char *uniqueArray;

    //ask user to enter string
    printf("Enter string: ");
    gets(array);
    uniqueArray = findUnique(array);
    printf("%s", uniqueArray);
    return 0;
}

char* findUnique(char array[])
{
    int length, i, j, k = 0, count = 0;
    char *newArray;
    newArray = (char*) malloc(100 * sizeof(char));

    // get the length of the string
    length = strlen(array);

    for (i = 0; i < length; i++) {
        for (j = 0; j < length; j++) {
            if (array[i] == array[j]) {
                count++;
            }
        }
        if (count == 1) {
            newArray[k] = array[i];
            k++;
        }
        count = 0;
    }

    newArray[k] = 0;
    newArray = (char *) realloc(newArray, k * sizeof(char));
    return newArray;
}
