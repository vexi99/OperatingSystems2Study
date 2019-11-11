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
void push(StackNode* *headPtr, int info);
int pop(StackNode* *headPtr);
void printStack(StackNode* *headPtr);

void main()
{
   menu();

}

void push(StackNode* *headPtr, int info)
{
   StackNode* newPtr = malloc(sizeof(StackNode));

   if (newPtr != NULL)
   {
      newPtr->value = info; //user inputted info is placed in value field
      newPtr->nextPtr = *headPtr; //newPtr's nextPtr is pointed to the current top of the stack
      *headPtr = *newPtr; //newPtr's data is then assigned to the headPtr field, becoming the head of the stack.
   }
   else
   {
      printf("Not created properly");
   }
}

int pop(StackNode* *headPtr)
{
   StackNode* tempPtr = *headPtr;
   int poppedVal = (*headPtr)->value;
   *headPtr = (*headPtr)->nextPtr;
   free(tempPtr);
   return poppedVal;
}

void printStack(StackNode* *headPtr)
{
   
}

void menu(void)
{
    printf("Please choose  a value between 1 and 3:\n 1: Insert a character\n 2: Delete a character\n 3: Quit program.");
}