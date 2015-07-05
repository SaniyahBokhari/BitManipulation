/******************************************************************************
/ C++ program that converts a selection of byte values to 8 bit representation. 
/
*******************************************************************************/

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;


string ConvertIntToBinary(char value)
{
   string binary_string = "";
   int i; 
   unsigned char probe = 0x80; // Equivalent to binary 1000 0000
   unsigned char result;

   for(i=0;i<8;i++){ // Probe bit positions from left to right
      result = probe & value;
      binary_string += (result!=0) ? "1" : "0"; 
      probe = probe >> 1; // Shift probe 1 position to the right and 
                          // fill left hand side with zeros
   }
   return binary_string;
}

int main()
{
   char vals[13] = {0,1,2,64,65,125,126,127,-128,-127,-64,-2,-1};  
   
   for(int i=0;i<13;i++){
      cout << setw(4) << (int)vals[i] << setw(9) << ConvertIntToBinary(vals[i]) << endl;
   }
   return 0;
}
