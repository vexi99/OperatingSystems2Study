// Dietel and Dietel C programming ed 7 12.3
// Inserting and deleting nodes in to an ordered list.


#include <stdio.h>
#include <stdlib.h>

// self-referential structure                      
struct listNode {                                      
   char data; // each listNode contains a character 
   struct listNode *nextPtr; // pointer to next node
}; 

typedef struct listNode ListNode; // synonym for struct listNode


// prototypes
void insert(ListNode* *sPtr, char value); //The Insert to list Function
char delete(ListNode* *sPtr, char value); // Delete from list Function
void printList(ListNode* currentPtr); // Print of list to standard output Function
void menu(void); //Prints the menu for the user

int main(void)
{ 
   ListNode* Head = NULL; // initially there are no nodes, HEAD is created and given a value of NULL.
   char item; // char entered by user, will be added to list

   menu(); // display the menu
   printf("%s", "? ");
   unsigned int choice; // user's choice
   scanf("%u", &choice);

   // loop while user does not choose 3
   while (choice != 3) { 

      switch (choice) 
      { 
         //insert value
         case 1:
            printf("%s", "Enter a character: "); //character to be added to the list
            scanf("\n%c", &item);
            insert(&Head, item); // insert character to the list, Address of head pointer and the character variable are passed to the insert function
            printList(Head); //print out the new linked list after the new character has been added.
            break;
         case 2: // delete an element

            //check if list is not empty, cannot delete from an empty list, if head does not equal null, there is data in the list.
            if (Head != NULL) 
            { 
               printf("%s", "Enter character to be deleted: ");
               scanf("\n%c", &item); //read in what item user wants to be removed from list into variable "item".

               // if character is found, remove it, delete function is called, head pointer and item to be deleted is passed to the function.
               if (delete(&Head, item)) 
               { 
                  //item has been removed from the list. PrintList function is called to show user new list order.
                  printf("%c deleted.\n", item);
                  printList(Head);
               } 
               
               //else, the item was not found in the list and therefore could not be deleted.
               else 
               {
                  printf("%c not found.\n\n", item);
               } 
            } 
            //else, list is empty, as Head == NULL. cannot delete item from an empty list.
            else 
            {
               puts("List is empty.\n");
            } 

            break;
         default:
            puts("Invalid choice.\n");
            menu();
            break;
      } // end switch

      printf("%s", "? ");
      scanf("%u", &choice);
   } 

   puts("End of run.");
} 

// display program instructions to user
void menu(void)
{ 
   puts("Enter your choice:\n"
      "   1 to insert an element into the list.\n"
      "   2 to delete an element from the list.\n"
      "   3 to end.");
} 

// insert a new value into the list in sorted order
void insert(ListNode* *sPtr, char value)
{ 
   ListNode* newPtr = malloc(sizeof(ListNode)); //memory allocated for new ListNode Structure

   if (newPtr != NULL) //if statement to check if newPtr has been created properly (ie has data/ pointer address appointed to it)
   { 
      newPtr->data = value; //value of char inputted by user is placed into newPtr
      newPtr->nextPtr = NULL; //nextPtr pointed to NULL

      ListNode* previousPtr = NULL; //previousPtr node Created, pointed to NULL
      ListNode* currentPtr = *sPtr; //currentPtr node Created, pointed to sPtr which is the "Head" of the List

            
      while (currentPtr != NULL && value > currentPtr->data) //while currentPtr isnt equal to NULL(Has Data) and Value is greater than the data of currentPtr (this while loop is to have an ordered List) 
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
      printf("%c not inserted. No memory available.\n", value);
   } 
} 

// delete a list element, Head pointer and value that the user input is passed to delete function
char delete(ListNode* *sPtr, char value)
{ 
   // delete first node if a match is found, if user input value is equal to head pointer data, the lines of code are ran inside this IF statement
   if (value == (*sPtr)->data) 
   { 
      ListNode* tempPtr = *sPtr; //tempPtr struct is created and pointed to head pointer, (ie the item to be deleted)
      *sPtr = (*sPtr)->nextPtr; //head pointer is "moved" along to the next element in the list
      free(tempPtr); //the memory allocated for tempPtr is freed, deleting it from memory.
      return value; //value is returned to main.
   } 

   else //the code in this else statement is ran if the first element in the list does not equal the item in which users wish to delete from the list.
   { 
      ListNode* previousPtr = *sPtr; //previousPtr struct created and given values of the head of the list
      ListNode* currentPtr = (*sPtr)->nextPtr; //currentPtr struct created and given the values of the next element in the list, essentially pushing the list up to the next item.

      while (currentPtr != NULL && currentPtr->data != value) //loop while currentPtr isnt equal to NULL and the data in currentPtr does not equal to the user inputted value, loop ends when correct match is found.
      { 
         previousPtr = currentPtr; //previousPtr given value of currentPtr
         currentPtr = currentPtr->nextPtr; //currentPtr given value of nextPtr in list, moving the list along 
      } 
      
      if (currentPtr != NULL) //if statement triggered, if the currentPtr struct is not empty (ie has data), this is where the data will be deleted once the match is found
      { 
         ListNode* tempPtr = currentPtr; //tempPtr struct is created to temporeraily hold the data of the currentPtr struct
         previousPtr->nextPtr = currentPtr->nextPtr; //nextPtr field in previousPtr is filled with data from the nextPtr field in the currentPtr struct, moving the list along by one
         free(tempPtr); //the memory allocated for tempPtr is freed from the program, deleting it.
         return value;
      } 
   } 

   return '\0';   // '\0' is the null character (equivalent to returning false) 
} 


// print the current list to standard output
void printList(ListNode* currentPtr)
{ 
   
   if (currentPtr == NULL) 
   {
      puts("List is empty.\n");
   } 
   else 
   { 
      puts("The list is:");

      // while not the end of the list
      while (currentPtr != NULL) { 
         printf("%c --> ", currentPtr->data); //print the character stored in the currentPtr data section
         currentPtr = currentPtr->nextPtr;   //currentPtr is moved along the list, "incrementing" it by one to the next element in the linked list.
      } 

      puts("NULL\n"); //end of the list
   } 
} 




/**************************************************************************
 * (C) Copyright 1992-2015 by Deitel & Associates, Inc. and               *
 * Pearson Education, Inc. All Rights Reserved.                           *
 *                                                                        *
 * DISCLAIMER: The authors and publisher of this book have used their     *
 * best efforts in preparing the book. These efforts include the          *
 * development, research, and testing of the theories and programs        *
 * to determine their effectiveness. The authors and publisher make       *
 * no warranty of any kind, expressed or implied, with regard to these    *
 * programs or to the documentation contained in these books. The authors *
 * and publisher shall not be liable in any event for incidental or       *
 * consequential damages in connection with, or arising out of, the       *
 * furnishing, performance, or use of these programs.                     *
 *************************************************************************/
