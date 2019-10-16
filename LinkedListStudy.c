// Dietel and Dietel C programming ed 7 12.3
// Inserting and deleting nodes in a list

// this adapted version has most of the comments removed.
// students are expected to inser their own commnents, 


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
   ListNode* Head = NULL; // initially there are no nodes, HEAD is created and given a value of NULL
   char item; // char entered by user, will be added to list

   menu(); // display the menu
   printf("%s", "? ");
   unsigned int choice; // user's choice
   scanf("%u", &choice);

   // loop while user does not choose 3
   while (choice != 3) { 

      switch (choice) { 
         case 1:
            printf("%s", "Enter a character: ");
            scanf("\n%c", &item);
            insert(&Head, item); // insert item in list
            printList(Head);
            break;
         case 2: // delete an element
            // if list is not empty
            if (Head != NULL) { 
               printf("%s", "Enter character to be deleted: ");
               scanf("\n%c", &item);

               // if character is found, remove it
               if (delete(&Head, item)) { // remove item
                  printf("%c deleted.\n", item);
                  printList(Head);
               } 
               else {
                  printf("%c not found.\n\n", item);
               } 
            } 
            else {
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

// delete a list element
char delete(ListNode* *sPtr, char value)
{ 
   // delete first node if a match is found
   if (value == (*sPtr)->data) { 
      ListNode* tempPtr = *sPtr; 
      *sPtr = (*sPtr)->nextPtr; 
      free(tempPtr); 
      return value;
   } 
   else { 
      ListNode* previousPtr = *sPtr;
      ListNode* currentPtr = (*sPtr)->nextPtr;

      
      while (currentPtr != NULL && currentPtr->data != value) { 
         previousPtr = currentPtr; 
         currentPtr = currentPtr->nextPtr;  
      } 

      
      if (currentPtr != NULL) { 
         ListNode* tempPtr = currentPtr;
         previousPtr->nextPtr = currentPtr->nextPtr;
         free(tempPtr);
         return value;
      } 
   } 

   return '\0';   // '\0' is the null character (equivalent to returning false) 
} 


// print the list
void printList(ListNode* currentPtr)
{ 
   
   if (currentPtr == NULL) {
      puts("List is empty.\n");
   } 
   else { 
      puts("The list is:");

      // while not the end of the list
      while (currentPtr != NULL) { 
         printf("%c --> ", currentPtr->data);
         currentPtr = currentPtr->nextPtr;   
      } 

      puts("NULL\n");
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
