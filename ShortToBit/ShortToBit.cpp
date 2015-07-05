/********************************************************************************
/ C++ Program that converts a selection of short values to 16 bit representation. 
/
*********************************************************************************/

#include <iostream>
#include <string>
#include <iomanip>
#include <climits>
using namespace std;


string ConvertShortToBinary(short integer_value)
{
   string binary_string = "";
   int i; 
   unsigned short probe = 0x8000; // Equivalent to 16 bits in binary 
                                  // with 1 in the left most position
                                  // and zeroes elsewhere

   unsigned short result;
   for(i=0;i<16;i++){ // Probe bit position from left to right
      result = probe & integer_value;
      binary_string += (result!=0) ? "1" : "0"; 
      probe = probe >> 1; // Shift probe 1 position to the right
                          // and fill left hand side with zeros

   }
   return binary_string;
}

int main()
{
   for(short i=0;i<4;i++){ // Print out the 4 smallest values of short in binary
      short value = (short)(SHRT_MIN+i);
      cout << setw(6) << value << setw(17) << ConvertShortToBinary(value) << endl;
   }
 
   cout << endl;

   for(short i=-4;i<=4;i++){ // Print out values of short in binary from -4 to 4 
      cout << setw(6) << i << setw(17) << ConvertShortToBinary(i) << endl;
   }

   cout << endl;

   for(short i=3;i>=0;i--){ // Print out the 4 largest values of short in binary
      short value = (short)(SHRT_MAX-i);
      cout << setw(6) << value << setw(17) << ConvertShortToBinary(value) << endl;
   }

   return 0;
}
