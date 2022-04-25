#include <stdio.h>
#include <string.h>

typedef struct{
    char name[30];
    int HP;
    int attackPower;
} character;

typedef enum{
    Earth, Fire, Wind
} Element;

typedef union{
    
}

character getCharacterInfo();
void getInfoOfManyCharacters(character[], int);
void display(character);
void displayCharacters(character[], int);
void attack(character[], int);

int main(){
    character characters[2];
    getInfoOfManyCharacters(characters, 2);
    attack(&characters, 2);
    displayCharacters(characters, 2);
}

character getCharacterInfo(){
    character chars;
    printf("Enter name: ");
    scanf("%s", chars.name);
    printf("Enter element: ");
    scanf("%s", chars.element);
    printf("Enter HP: ");
    scanf("%d", &chars.HP);
    printf("Enter Attack Power: ");
    scanf("%d", &chars.attackPower);
    return chars;
}

void getInfoOfManyCharacters(character chars[], int size){
    int i;
    for(i = 0; i < size; i++)
    {
        chars[i] = getCharacterInfo();
    }
}

void display(character chars){
    printf("Name: %s", chars.name);
    printf("\nElement: %s", chars.element);
    printf("\nHP: %d", chars.HP);
    printf("\nAttack Power: %d", chars.attackPower);
}


void attack(character *chars, int size){
    int i;
    if(chars[0].attackPower > chars[1].attackPower){
        chars[1].HP -= 10;
    }
}

void displayCharacters(character chars[], int size){
    int i;
    for(i = 0; i < size; i++)
    {
        display(chars[i]);
    }
}