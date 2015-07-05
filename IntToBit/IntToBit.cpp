/*************************************************************************
/ Reads an int and converts it into bit representation in c++ 
/
/
/ from the standard input
/ or
/ redirect from file
/
**************************************************************************/

#include <iostream>
#include <string>
using namespace std;


string ConvertIntToBinary(int integer_value)
{
   string binary_string = "";
   int i; 
   unsigned int probe = 0x80000000, result;
   for(i=0;i<32;i++){
      result = probe & integer_value;
      binary_string += (result!=0) ? "1" : "0"; 
      probe = probe >> 1;
   }
   return binary_string;
}

int main()
{
   int integer_value;
   while(!cin.eof()) {
      cout << "Enter an integer value: ";
      cin >> integer_value;
      cout << "The binary representation is: ";
      string binary_string = ConvertIntToBinary(integer_value);
      cout << binary_string << "\n";
   }
    return 0;
}
