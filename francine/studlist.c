#include <stdio.h>
#include <string.h>
#define SIZE 30

typedef struct{
    char LName[16];
    char FName[24];
    char MI;
} Nametype;

typedef struct{
    Nametype name;
    int ID;
    char course[8];
    int year;
} Studtype;

typedef struct{
    Studtype stud[SIZE];
    int count;
} StudList;

void initializeList(StudList*);
void addStudent(StudList*, Studtype);
int findElem(int, StudList);

int main() {
    int elementExists;
    StudList List;
    Studtype record;

    initializeList(&List);
    addStudent(&List, record);
    List.count = 10;
    record.ID = 5;
    List.stud[5].ID = 5;
    elementExists = findElem(record.ID, List);
    printf("%d", elementExists);
    return 0;
}

void initializeList(StudList *List)
{
    List->count = 0;
}

void addStudent(StudList *List, Studtype record)
{
    if (List->count < SIZE)
    {
        List->stud[List->count] = record;
        List->count++;
    }
}

int findElem(int ID, StudList List)
{
    int i, val = 0;

    for (i = 0; i < List.count; i++)
    {
        if (ID == List.stud[i].ID)
        {
            val = 1;
        }
    }
    return val;
}