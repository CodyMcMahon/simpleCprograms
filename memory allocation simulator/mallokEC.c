#include <stdio.h>
#include <stdlib.h>
/**
  *   I put the node in the front of each block. Then I 
  *   adjusted everything accordingly. instead of freeing
  *   all the things I did the first time I just ignored
  *   the unused stuff and maked the block as free. The 
  *   amount of memory taken from ram is always what you
  *   tell it to be but you are not able to use it all.
  *   if you call a memory_pool of 1000 it takes from that
  *   to make nodes which take up space so you probably 
  *   will only get like 800 or so to use for yourself.
  */
typedef struct abc123{
   void* position;
   int size;
   int isFree;
   struct abc123* next;
} memoryNode;

static void* front = NULL;
static memoryNode* frontNode = NULL;
static int poolSize = 0;

//can only call this function once
void create_pool(int size){
   if (front == NULL){
      front = calloc(size, 1);
      poolSize = size;
      frontNode = (memoryNode*) front;
      frontNode->position = front + sizeof(memoryNode);
      frontNode->size = size - sizeof(memoryNode);
      frontNode->isFree = 69;
      frontNode->next = 0;
   }
}

void *my_malloc(int size)
{
   memoryNode* newNode;
   memoryNode* temp = frontNode;
   while(temp){
      if (temp->isFree && ((temp->size) >= (size + sizeof(memoryNode)))){
         break;
      }
      temp = temp->next;
   }
   if (temp){
      if (temp->size == size + sizeof(memoryNode)){
         temp->isFree = 0;
         newNode = temp;
      }
      else{
         temp->size -= (size + sizeof(memoryNode));
         newNode = (memoryNode*) (temp->position + temp->size);
         newNode->size = size;
         newNode->isFree = 0;
         newNode->next = temp->next;
         //temp->size -= newNode->size + sizeof(memoryNode);
         temp->next = newNode;
         newNode->position = ((void*)newNode) + sizeof(memoryNode);
      }
   }
   else {
      return 0;
   }
   return newNode->position;
}

void cleanFreeCells(){
   memoryNode* temp = frontNode;
   while (temp){
      if (temp->next && temp->isFree){
         if (temp->next->isFree){
            temp->size += (temp->next->size + sizeof(memoryNode));
            temp->next = temp->next->next;
            
         }
      }
      temp = temp->next;
   }

   
}
void my_free(void *block){
   memoryNode* temp = frontNode;
   if(block == 0)
      return;
   while (temp){
      if (temp->position == block){
         temp->isFree++;
         break;
      }
      temp = temp->next;
   }
   cleanFreeCells();
}
