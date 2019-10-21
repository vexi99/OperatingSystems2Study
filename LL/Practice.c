//File to practice the creation of Linked Lists

#include <stdio.h>
#include <stdlib.h>

//self-refrenctial structure:
struct stackNode {
    int value; //user inputted value
    struct stackNode *nextPtr; //struct created for the nextPtr in the list.
};// end struct

typedef struct stackNode StackNode;
//prototypes
void menu(void);
void push(StackNode* *headPtr, int val);

void main()
{
   menu();

}

void push(StackNode* *headPtr, int val)
{
   
}

void menu(void)
{
    printf("Please choose  a value between 1 and 3:\n 1: Insert a character\n 2: Delete a character\n 3: Quit program.");
}