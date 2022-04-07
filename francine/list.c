#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    char data;
    struct node* link;
}nodetype, *LIST;

void insertLast(LIST *, char);
void insertSorted(LIST *, char);
void deleteElem(LIST *, char );
void deleteAllOccur(LIST *, char);

int main() {
    LIST L;
    char element;
    insertLast(&L, element);
    insertSorted(&L, element);
    deleteElem(&L, element);
    deleteAllOccur(&L, element);
    return 0;
}

void insertLast(LIST *L, char element)
{
  LIST temp;
  temp = (LIST)malloc(sizeof(nodetype));
  temp->data = element;
  temp->link = NULL;
  if(*L == NULL)
  {
    *L = temp;
  }
}

void insertSorted(LIST *L, char element)
{
  LIST temp;
  temp = (LIST)malloc(sizeof(nodetype));
  for(temp = *L; temp != NULL; temp = temp->link)
    {
      if(temp->data > element)
      {
        temp->data = element;
        temp->link = *L;
      }
    }
}

void deleteElem(LIST *L, char element)
{
  LIST temp;
  temp = (LIST)malloc(sizeof(nodetype));
  for(temp = *L; temp != NULL; temp = temp->link)
    {
      if(element == temp->data)
      {
        free(temp);
        break;
      }
    }
}

void deleteAllOccur(LIST *L, char element)
{
  LIST temp;
  temp = (LIST)malloc(sizeof(nodetype));
  for(temp = *L; temp != NULL; temp = temp->link)
    {
      if(element == temp->data)
      {
        free(temp);
      }
    }
}
