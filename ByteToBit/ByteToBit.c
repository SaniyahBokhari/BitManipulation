/****************************************************************************
/ C program that converts a selection of byte values to 8 bit representation. 
/
*****************************************************************************/

#include <stdio.h>
#include <stdlib.h>


char *ConvertIntToBinary(char char_value)
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

int main()
{
   char vals[13] = {0,1,2,64,65,125,126,127,-128,-127,-64,-2,-1};  
   int i;
   for(i=0;i<13;i++){
      char* binary_string = ConvertIntToBinary(vals[i]);
      printf("%4d %s\n",vals[i],binary_string);
      free(binary_string);
   }      
   return 0;
}
