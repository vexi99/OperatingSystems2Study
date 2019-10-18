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
    ListNode* newPtr = malloc(sizeof(ListNode)); //memory allocated for new ListNode Structure

   if (newPtr != NULL) //if statement to check if newPtr has been created properly (ie has data/ pointer address appointed to it)
   { 
      newPtr->value = val; //value of char inputted by user is placed into newPtr
      newPtr->nextPtr = NULL; //nextPtr pointed to NULL

      ListNode* previousPtr = NULL; //previousPtr node Created, pointed to NULL
      ListNode* currentPtr = *sPtr; //currentPtr node Created, pointed to sPtr which is the "Head" of the List

      //while currentPtr isnt equal to NULL(Has Data) and Value is greater than the data of currentPtr (this while loop is to have an ordered List)            
      while (currentPtr != NULL && val > currentPtr->value)  
      {
         previousPtr = currentPtr; //PreviousPtr is turned into the currentPtr            
         currentPtr = currentPtr->nextPtr; //CurrentPtr is turned into nextPtr, these two lines of code essentially "push" the location where the node will be inserted along, until correct position is found
      }                                          

      //insert new node at beginning of list, head is made point towards the nextPtr and Head is also given the data of the newPtr
      if (previousPtr == NULL) { 
         newPtr->nextPtr = *sPtr; //the nextPtr is pointed towards the Head of the list
         *sPtr = newPtr; //The head of the list is then given to newPtr
      } 
      //insert new node between previousPtr and currentPtr
      else {
         previousPtr->nextPtr = newPtr;//the "previous" item's nextPtr field in the list is pointed towards the new item which is just added to the list
         newPtr->nextPtr = currentPtr;//The new item's nextPtr field is pointed towards the currentPtr in the list
         // List is now changed from "previousPtr->currentPtr" to "previousPtr->newPtr->currentPtr" essentially as newPtr is placed between them.
      } 
   } 
   else { //if newPtr does equal NULL, value has not been correctly inserted to the list.
      printf("%c not inserted. No memory available.\n", val);
   } 
}

void menu(void)
{
    printf("Please choose  a value between 1 and 3:\n 1: Insert a character\n 2: Delete a character\n 3: Quit program.");
}