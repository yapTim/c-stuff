#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    char data;
    struct node* link;
}nodetype, *LIST;

void displayList(LIST);
void initList(LIST*);
void insertFirst(LIST*, char);

int main() 
{
  char element = 'C';
  LIST L;
  displayList(L);
  initList(&L);
  insertFirst(&L, element);
  return 0;
}

void displayList(LIST L)
{
  LIST temp;
  for(temp = L; temp != NULL; temp = temp->link)
    {
      printf("%c", temp->data);
    }
}

void initList(LIST *L)
{
  LIST temp;
  temp = (LIST)malloc(sizeof(nodetype));
  temp->link = NULL;
}

void insertFirst(LIST *L, char element)
{
  LIST temp;
  temp = (LIST)malloc(sizeof(nodetype));
  temp->data = element;
  temp->link = *L;
  *L = temp;
}