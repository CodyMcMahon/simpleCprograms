/*Cody McMahon*/
//reads a book and
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
int formatString(char* theString){
   int i, o, length = strlen(theString);
   for( i = 0; i < length; i++){
      if (theString[i] > 64 && theString[i] < 91){
         theString[i] += 32;
      }
      else if ((theString[i] > 96 && theString[i] < 123) || theString[i] == 39 || theString[i] == 45);
      else{
         for ( o = i; o < length; o++){
            theString[o] = theString[o+1];
         }
         theString[length] = 0;
         i--;
         length--;
      }
   }
   theString[length] = 0;
   return length + 1;
}
int readFile1(char* words){
   int i, temp, bookMark = 0;
   FILE *inFile = fopen("LittleRegiment.txt", "r");
   while (fscanf(inFile,"%s",words) > 0) {
      temp = (formatString(words));
      addList(words, 1);
      words += temp;
      bookMark += temp;
   }
   return bookMark;
}
void readFile2(char* words){
   int i, temp;
   FILE *inFile = fopen("RedBadge.txt", "r");
   while (fscanf(inFile,"%s",words) > 0) {
      temp = (formatString(words));
      addList(words, 0);
      words += temp;
   }
}
int main(){
   int bookMark;
   //everything is saved in one giant string seperated by NULL terminators ('\0')
   char* words = (char*)calloc(1000000, 1);
   bookMark = readFile1(words);
   readFile2(&words[bookMark]);
   sortList();
   printList();
}
