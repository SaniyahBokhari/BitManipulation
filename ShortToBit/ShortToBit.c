/*******************************************************************************
/ C Program that converts a selection of short values to 16 bit representation. 
/
********************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


char *ConvertShortToBinary(short integer_value)
{
   char* binary_string=malloc(17*sizeof(char));
   int i;
   short probe = 1, result;
   binary_string[16] = '\0';
   for(i=15;i>=0;i--){ // Probe bit positions from right to left
      result = probe & integer_value;
      binary_string[i] = (result!=0)?'1':'0';      
      probe = probe << 1; // Shift probe 1 position to the left and 
                          // fill right hand side with zeros
   }
   return binary_string;
}

int main()
{
   short i;
   for(i=0;i<4;i++){ // Print out the 4 smallest values of short in binary
      short value = (short)(SHRT_MIN+i);
      char* binary_string = ConvertShortToBinary(value);
      printf("%6d %s\n",value,ConvertShortToBinary(value));
      free(binary_string);
   }
 
   printf("\n");
       
   for(i=-4;i<=4;i++){ // Print out values of short in binary from -4 to 4 
      char* binary_string = ConvertShortToBinary(i);
      printf("%6d %s\n",i,ConvertShortToBinary(i));
      free(binary_string);
   }

   printf("\n");

   for(i=3;i>=0;i--){ // Print out the 4 largest values of short in binary
      short value = (short)(SHRT_MAX-i);
      char* binary_string = ConvertShortToBinary(value);
      printf("%6d %s\n",value,ConvertShortToBinary(value));
      free(binary_string);
   } 

   return 0;
}
