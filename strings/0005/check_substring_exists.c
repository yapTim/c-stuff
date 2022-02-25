#include <stdio.h>
#include <string.h>
#define MAX_SIZE 100

enum boolean {
    FALSE = 0,
    TRUE = 1
};

typedef enum boolean Boolean;

Boolean checkSubstringExists(char[], char[]);

int main()
{
    char string[MAX_SIZE], substring[MAX_SIZE];

    printf("Enter String: ");
    gets(string);
    printf("Enter Substring: ");
    gets(substring);

    if (checkSubstringExists(string, substring) == TRUE) {
        puts("The substring exists.");
    } else {
        puts("The substring doesn't exist.");
    }

    return 0;
}

Boolean checkSubstringExists(char string[], char substring[])
{
    int i, j = 0, stringLength, substringLength;
    Boolean match = FALSE;

    stringLength = strlen(string);
    substringLength = strlen(substring);

    for (i = 0; i < stringLength; i++) {
        if (string[i] == substring[j]) {
            j++;
        } else if (string[i] == substring[0]) {
            j = 1;
        } else {
            j = 0;
        }

        if (j == substringLength) {
            match = TRUE;
        }
    }

    return match;
}
