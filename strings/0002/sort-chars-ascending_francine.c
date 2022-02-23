#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *sortAscending(char[]);

int main()
{
    char origArray[100];
    char *newArray;
    int i, length;

    //ask user to enter string
    printf("Enter string: ");
    gets(origArray);
    length = strlen(origArray);

    //function call
    newArray = sortAscending(origArray);

    for (i = 0; i < length; i++) {
        printf("%c", newArray[i]);
    }

    return 0;
}

char *sortAscending(char originalArray[])
{
    char *newArray, temp;
    int length, i, j, k = 0;

    //get length of originalArray
    length = strlen(originalArray);

    for (i = 0; i < length - 1; i++) {
        for (j = 0; j < length - i - 1; j++) {
            if (originalArray[j] > originalArray[j+1]) {
                temp = originalArray[j];
                originalArray[j] = originalArray[j+1];
                originalArray[j+1] = temp;
            }
        }
    }

    return originalArray;
}
