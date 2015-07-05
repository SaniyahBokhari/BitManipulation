/*************************************************************************
/ Reads an int and converts it into bit representation in c 
/
/
/ from the standard input
/ or
/ redirect from file
/
**************************************************************************/

#include <stdio.h>
#include <stdlib.h>


char *ConvertIntToBinary(int integer_value)
{
   char* binary_string=malloc(33*sizeof(char));
   int i, probe = 1, result;
   binary_string[32] = '\0';
   for(i=31;i>=0;i--){
      result = probe & integer_value;
      binary_string[i] = (result!=0)?'1':'0';      
      probe = probe << 1;
   }
   return binary_string;
}

int main()
{
   int integer_value;
   do{
      printf("Enter an integer value: ");   
      scanf("%d",&integer_value);
      printf("The binary representation is: ");
      char *binary_string = ConvertIntToBinary(integer_value);
      printf("%s\n",binary_string); 
      free(binary_string);
   }while(!feof(stdin));      
   return 0;
}
