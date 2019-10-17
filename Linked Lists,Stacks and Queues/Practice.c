//File to practice the creation of Linked Lists

#include <stdio.h>
#include <stdlib.h>

//self-refrenctial structure:
struct listNode {
    char value; //user inputted value
    struct listNode *nextPtr; //struct created for the nextPtr in the list.
};// end struct

typedef struct listNode ListNode;
//prototypes
void menu(void);

void main()
{
    menu();
}

void menu(void)
{
    printf("Please choose  a value between 1 and 3:\n 1: Insert a character\n 2: Delete a character\n 3: Quit program.");
}