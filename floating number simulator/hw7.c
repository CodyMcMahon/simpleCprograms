#include <stdio.h>
#include <stdlib.h>

typedef union{
   unsigned int binary;
   float actualNum;
} floater;

int getBDigit(unsigned int num, int digit){
   int i;
   for(i = 0; i < digit; i++){
      num = num / 2;
   }
   return num % 2;
}

char getEX(unsigned int num){
   unsigned char temp = 0;
   signed char EX;
   int i, o, z;
   for(i = 23; i < 31; i++){
      z = getBDigit(num, i);
      for(o = 0; o < i-23; o++)
         z *= 2;
      temp += z;
   }
   EX = temp - 127;
   return EX;
}

int main(){
   int i, temp;
   char EX;
   float helper = 1, tempf = 1;
   floater myFloat;
   printf("Enter a float: ");
   scanf("%f", &myFloat.actualNum);
   printf("Your float was read as: %.6f\n", myFloat.actualNum);
   printf("your float in 32 bits: ");
   for(i = 31; i >= 0; i--){
      printf("%d",getBDigit(myFloat.binary, i));
   }
   printf("\nSign: %d\nExponent: ", getBDigit(myFloat.binary,i));
   for(i = 30; i >= 23; i--){
      printf("%d",getBDigit(myFloat.binary, i));
   }
   printf("\nFraction: ");
   for(i = 22; i >= 0; i--){
      printf("%d",getBDigit(myFloat.binary, i));
   }
   printf("\n\nCreating the fraction:\nfraction = %.6f (the implicit 1)\n", helper);
   for(i = 22; i >= 0; i--){
      tempf = tempf / 2;
      if (getBDigit(myFloat.binary, i))
         printf("fraction = %.6f, after adding %.6f\n", helper += tempf, tempf);
      else
         printf("fraction = %.6f, after skipping %.6f\n", helper, tempf);
   }
   printf("\nApplying the exponenet:\nunbiased exponent = %d\n", EX = getEX(myFloat.binary));
      for(i = 0; i < EX; i++)
         printf("times 2 = %.6f\n", helper *= 2);
      for(i = 0; i > EX; i--)
         printf("divided by 2 = %.6f\n", helper /= 2);
   if(getBDigit(myFloat.binary,31))
      helper *= -1;
   printf("\nFinal Answer: %.6f\n\n", helper);
}
