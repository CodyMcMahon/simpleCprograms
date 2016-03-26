#include "mallok.h"
#include <stdio.h>

int main(){
   create_pool(3000);
   void* test[3000];
   int i,o,checker;



   //**test1**
   for (i = 0;;i++){
      test[i] = my_malloc(5);
      if(test[i]);else break;
   }
   o = i;
   for(;i >= 0;i--){
      my_free(test[i]);
   }
   for(i=0;i<o;i++){
      test[i] = my_malloc(5);
      if(test[i]);else checker++;
   }
   for(i=0;i<o;i++)
      my_free(test[i]);
   if(checker)printf("you failed test 1\n");
   else printf("test1 passed!\n");
   /* */



   //**test2**
      checker = 0;
   test[1] = my_malloc(200);
   test[2] = my_malloc(200);
   char* blockA = (char*) test[1];
   char* blockB = (char*) test[2];
   for( i = 0; i < 200; i++)
      blockA[i] = 'A';
   for( i = 0; i < 200; i++)
      blockB[i] = 'B';
   for( i = 0; i < 200; i++)
      if(blockA[i] != 'A')checker++;
   for( i = 0; i < 200; i++)
      if(blockB[i] != 'B')checker++;
   if(checker)
      printf("YOU HAVE FAILED TEST 4!\n");
   else
      printf("test2 passed!\n");
   my_free(test[1]);
   my_free(test[2]);





   /* */
   
   //**test 3**
   test[1] = my_malloc(200);
   test[2] = my_malloc(200);
   test[3] = my_malloc(200);
   test[4] = my_malloc(200);
   test[5] = my_malloc(200);
   for(i=0;i<50&&test[1]&&test[2]&&test[3]&&test[4]&&test[5];i++){
   
   my_free(test[1]);
   my_free(test[2]);
   my_free(test[3]);
   my_free(test[4]);
   my_free(test[5]);
   test[1] = my_malloc(200);
   test[2] = my_malloc(200);
   test[3] = my_malloc(200);
   test[4] = my_malloc(200);
   test[5] = my_malloc(200);
   }
   if(i=50)printf("test3 passed!\n");
   if(my_malloc(1))("YOU HAVE FAILED TEST 3!!!!!!!\n");
   my_free(test[1]);
   my_free(test[2]);
   my_free(test[3]);
   my_free(test[4]);
   my_free(test[5]);
   /* */
   //I really can't know how to test this one for passing or failing
   //with the knowledge I have now.
   //**test 4**
   
   i = 0;
   void* thing = my_malloc(521);
   while(thing){
      thing = my_malloc(521);
      i++;
   } 
   printf("on test 4 is created %d blocks of size 521\n", i);
   
   /* */


}
