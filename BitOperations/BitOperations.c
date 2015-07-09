/*****************************************************************
/ C program to Demonstrate Bit Operations. 
/
******************************************************************/

#include <stdio.h>
#include <stdlib.h>



char *ConvertByteToBinary(char char_value)
{
   char* binary_string=malloc(9*sizeof(char));
   int i;
   char  probe = 1, result;
   binary_string[8] = '\0';
   for(i=7;i>=0;i--){ // Probe bit positions from right to left
      result = probe & char_value;
      binary_string[i] = (result!=0)?'1':'0';      
      probe = probe << 1; // Shift probe 1 position to the left and 
                          // fill right hand side with zeros
   }
   return binary_string;
}

void printAnswer(char value1, char value2, char result, char operation){
       printf("......................\n");       
       printf("The %c operation: \n",operation);
       printf("......................\n");       
       printf("%9s %5d\n",ConvertByteToBinary(value1),value1);
       printf("%6c %7c\n",operation,operation);
       printf("%9s %5d\n",ConvertByteToBinary(value2),value2);
       printf("%6c %7c\n",'=','=');
       printf("%9s %5d\n",ConvertByteToBinary(result),result);
       printf("......................\n");       
       printf("\n");
}

void printAnswerNot(char value1, char result, char operation){
       printf("......................\n");       
       printf("The %c operation: \n",operation);
       printf("......................\n");       
       printf("%9s %5d\n",ConvertByteToBinary(value1),value1);
       printf("%6c %7c\n",operation,operation);
       printf("%6c %7c\n",'=','=');
       printf("%9s %5d\n",ConvertByteToBinary(result),result);
       printf("......................\n");       
       printf("\n");
}

int main()
{
   char val1 = -127;
   char val2 = 127;

   // AND Operation

   char AndResult = val1 & val2;
   printAnswer(val1,val2,AndResult,'&');

   // OR Operation

   char OrResult = val1 | val2;
   printAnswer(val1,val2,OrResult,'|');

   // XOR Operation

   char XorResult = val1 ^ val2;
   printAnswer(val1,val2,XorResult,'^');

   // NOT Operation

   char NotResult = ~val1;
   printAnswerNot(val1,NotResult,'~');

   // Shift Left Operation

   printf("......................\n");       
   printf("The << operation: \n");
   printf("......................\n"); 
   char result = val1;   
   printf("%9s %5d\n",ConvertByteToBinary(result),result);
   int i;
   for(i=0;i<8;i++){
      result = result << 1;
      printf("%9s %5d\n",ConvertByteToBinary(result),result);
   }
   printf("......................\n");       
   printf("\n");

   // Shift Right Operation

   printf("......................\n");       
   printf("The >> operation: \n");
   printf("......................\n"); 
   result = val1;   
   printf("%9s %5d\n",ConvertByteToBinary(result),result);
   for(i=0;i<8;i++){
      result = result >> 1;
      printf("%9s %5d\n",ConvertByteToBinary(result),result);
   }
   printf("......................\n");       
   printf("\n");


   return 0;   
}
