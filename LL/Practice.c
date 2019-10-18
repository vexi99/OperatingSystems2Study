//File to practice the creation of Linked Lists

#include <stdio.h>
#include <stdlib.h>

//self-refrenctial structure:
struct listNode {
    int value; //user inputted value
    struct listNode *nextPtr; //struct created for the nextPtr in the list.
};// end struct

typedef struct listNode ListNode;
//prototypes
void menu(void);
void insert(ListNode* *sPtr, int val);

void main()
{
    int userVal = 0;
    ListNode* Head = NULL; //New Node Head created, points to NULL as no other list elements exist at start of program.

    menu();

}

void insert(ListNode* *sPtr, int val)
{
    ListNode* newPtr = malloc(sizeof(ListNode)); //new struct called newPtr created

    if (newPtr != NULL)
    {
        newPtr->value = val; //assign user input value to the structure
        newPtr->nextPtr = NULL; //nextPtr points to NULL, as

        //create new structs, previousPtr and currentPtr
        ListNode* previousPtr = NULL;
        ListNode* currentPtr = NULL; 

        //while loop to find the space to input the value in correctly in ascending order.
        while(currentPtr != NULL && val > currentPtr->value)
        {
            previousPtr = currentPtr;
            currentPtr = currentPtr->nextPtr;
        }

        if(previousPtr == NULL)
        {
            newPtr->nextPtr = *sPtr;
            *sPtr = newPtr;
        }
        //insert new node between currentPtr and previousPtr
        else
        {
            /* this segment of code inserts newPtr inbetween previousPtr and currentPtr, by making previous point to newPtr and then newPtr point to currentPtr */
            previousPtr->nextPtr = newPtr;
            newPtr->nextPtr = currentPtr;
        }
        


    }
    else
    {
        //Code for failure to create struct.
        printf("Not enough memory to create the list.");
    }
    

}

void menu(void)
{
    printf("Please choose  a value between 1 and 3:\n 1: Insert a character\n 2: Delete a character\n 3: Quit program.");
}