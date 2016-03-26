/* Cody McMahon*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct  LIST_NODE{
   char* word;
   int count1;
   int count2;
   struct LIST_NODE* next;
} node;

node* head;
  
node* makeNode(){
   return (node*) calloc(1, sizeof(node));
}
/* this is never used */
void makeList() {
   head = (node*) calloc(1, sizeof(node));
}

void sortList() {
   int i = 1;
   node* temp;
   node holderNode;
   while(i){
      i = 0;
      temp = head;
      while (temp->next != NULL){
         if(fmin(temp->count1, temp->count2) < fmin(temp->next->count1, temp->next->count2)){
            i++;
            holderNode.count1 = temp->count1;
            holderNode.count2 = temp->count2;
            holderNode.word = temp->word;
            temp->count1 = temp->next->count1;
            temp->count2 = temp->next->count2;
            temp->word = temp->next->word;
            temp->next->count1 = holderNode.count1;
            temp->next->count2 = holderNode.count2;
            temp->next->word = holderNode.word;
         }
         temp = temp->next;
      }
   }
}

void printList() {
   int i;
   node* temp = head;
   for(i = 0; i < 50; i++){
      printf("#%d: %s \\\\   %d  \\\\  %d\n", i + 1, temp->word, temp->count1, temp->count2);
      temp = temp->next;
   }
}

void addList(char* word, int iscount2){
   node* temp = head;
   node* newNode;
   if (temp == NULL){
      newNode = makeNode();
      printf("Place: word \\\\  Red Badge  \\\\  Little Regiment\n");
      newNode->word = word;
      temp = newNode;
      if(iscount2)
         temp->count2++;
      else
         temp->count1++;
      head = temp;
   }
   else if (strcmp(temp->word, word) == 0){
      if(iscount2)
         temp->count2++;
      else
         temp->count1++;
   }
   else{
      while(temp->next != NULL){
         temp = temp->next;
         if(strcmp(temp->word, word) == 0){
            if(iscount2)
               temp->count2++;
            else
               temp->count1++;
            return;
         }
         
      }
      if (strcmp(temp->word, word) != 0){
         newNode = makeNode();
         newNode->word = word;
         temp->next = newNode;
         temp = newNode;
      }
      if(iscount2)
         temp->count2++;
      else
         temp->count1++;
   }      
}
