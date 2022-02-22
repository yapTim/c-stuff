#include <stdio.h>
#include <string.h>

void countFrequency(char[]);

int main()
{
    char array[100];

    //get string
    printf("Enter string: ");
    gets(array);

    //function call
    countFrequency(array);

    return 0;
}

void countFrequency(char array[])
{
    int length, i, j, count = 0, flag = 0;

    //get length of array
    length = strlen(array);

    for (i = 0; i < length; i++) {
        for (j = 0; j < length; j++) {
            if (array[i] == array[j]) {
                count++;
            }
        }
        printf("\n%c is repeated %d times", array[i], count);
        count = 0;
    }
}
