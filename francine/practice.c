/*Given a list sorted in ascending order according to last name, write the code of the 
function that will insert a given element at its proper position in the list. */
/*Given a list, write the code of the function that will delete the first occurrence of the
element bearing the given last name. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10

typedef struct{
  char Fname[24];
  char Mi;
  char Lname[16];
} Nametype;

typedef struct node{
  Nametype name;
  struct node* link;
} nodetype, *nameList;

typedef struct{
  Nametype names[MAX];
  int count;
}ArrayList;

void insertElement(nameList*, Nametype);
void insertElement2(ArrayList*, Nametype);
void deleteElement(nameList*, Nametype);
void deleteElement2(ArrayList*, Nametype);
void printList(nameList);
void printList2(ArrayList);

int main() {
    nameList L = NULL;
    Nametype givenName = {"Francine", 'G', "Borromeo"};
    Nametype givenName1 = {"AAA", 'A', "AAA"};
    Nametype givenName2 = {"CCC", 'C', "CCC"};
    ArrayList A;
    
    // insertElement(&L, givenName);
    // insertElement(&L, givenName1);
    // insertElement(&L, givenName2);
    // deleteElement(&L, givenName2);
    // printList(L);
    insertElement2(&A, givenName);
    insertElement2(&A, givenName1);
    insertElement2(&A, givenName2);
    deleteElement2(&A, givenName2);
    printList2(A);
    return 0;
}

void insertElement(nameList *L, Nametype given)
{
  
  nameList *temp;
  nameList newNode;
  newNode = (nameList)malloc(sizeof(nodetype));
  if(newNode != NULL)
  {
    newNode->name = given;
    newNode->link = NULL;
    for(temp = L; *temp != NULL && strcmp((*temp)->name.Lname, given.Lname) < 1; temp = &(*temp)->link)
      {}
        newNode->link = *temp;
        *temp = newNode;
  }
  
}

void printList(nameList L)
{
    nameList temp;
    for(temp = L; temp != NULL; temp = temp->link)
    {
        printf("%s %c %s", temp->name.Fname, temp->name.Mi, temp->name.Lname);
        
    }
}

void printList2(ArrayList L)
{
    int i;
    for(i = 0; i < L.count; i++)
    {
        printf("%s %c %s", L.names[i].Fname, L.names[i].Mi, L.names[i].Lname);
        
    }
}

void insertElement2(ArrayList* A, Nametype given)
{
  Nametype temp;
  Nametype new = given;
  int i;
  if(A->count < MAX)
  {
    for(i = 0; i < A->count; i++)
      {
          if(strcmp(A->names[i].Lname, given.Lname) > 0)
          {
              temp = A->names[i];
              A->names[i] = new;
              new = temp;
          }
      }
      A->count++;
      A->names[A->count-1] = new;
  }
}

void deleteElement(nameList *L, Nametype given)
{
  nameList *temp;
  nameList p;
  for(temp = L; *temp != NULL; temp = &(*temp)->link)
    {
      if(strcmp(given.Lname, (*temp)->name.Lname) == 0)
      {
        p = *temp;
        *temp = &(*temp)->link;
        free(p);
      }
    }
}

void deleteElement2(ArrayList *A, Nametype given)
{
  int i;
  for(i = 0; i < A->count; i++)
    {
      if(strcmp(A->names[i].Lname, given.Lname) == 0)
      {
        A->names[i] = A->names[i+1];
        given = A->names[i];
      }
    }
  A->count--;
}