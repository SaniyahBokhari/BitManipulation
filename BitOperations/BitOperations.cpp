/*****************************************************************
/ C++ program to Demonstrate Bit Operations. 
/
******************************************************************/

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

string ConvertByteToBinary(char value)
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

void printAnswer(char value1, char value2, char result, char operation){
       cout << "......................" << endl;       
       cout << "The "<< operation << " operation: " << endl;
       cout << "......................" << endl;       
       cout << setw(9) << ConvertByteToBinary(value1) << setw(5) << (int)value1 << endl;
       cout << setw(6) << operation << setw(7) << operation << endl;
       cout << setw(9) << ConvertByteToBinary(value2) << setw(5) << (int)value2 << endl;
       cout << setw(6) << '=' << setw(7) << '=' << endl;
       cout << setw(9) << ConvertByteToBinary(result) << setw(5) << (int)result << endl;
       cout << "......................" << endl;       
       cout << endl;       
}

void printAnswer(char value1, char result, char operation){
       cout << "......................" << endl;       
       cout << "The "<< operation << " operation: " << endl;
       cout << "......................" << endl;       
       cout << setw(9) << ConvertByteToBinary(value1) << setw(5) << (int)value1 << endl;
       cout << setw(6) << operation << setw(7) << operation << endl;
       cout << setw(6) << '=' << setw(7) << '=' << endl;
       cout << setw(9) << ConvertByteToBinary(result) << setw(5) << (int)result << endl;
       cout << "......................" << endl;       
       cout << endl;       
}

int main()
{
   char val1 = -127;
   char val2 = 5;

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
   printAnswer(val1,NotResult,'~');

   // Shift Left Operation

   cout << "......................" << endl;       
   cout << "The << operation: " << endl;
   cout << "......................" << endl;       
   char result = val2;   
   cout << setw(9) << ConvertByteToBinary(result) << setw(5) << (int)result << endl;
   for(int i=0;i<8;i++){
      result = result << 1;
      cout << setw(9) << ConvertByteToBinary(result) << setw(5) << (int)result << endl;
   }
   cout << "......................" << endl;       
   cout << endl;       

   // Shift Right Operation

   cout << "......................" << endl;       
   cout << "The >> operation: " << endl;
   cout << "......................" << endl;       
   result = val1;   
   cout << setw(9) << ConvertByteToBinary(result) << setw(5) << (int)result << endl;
   for(int i=0;i<8;i++){
      result = result >> 1;
      cout << setw(9) << ConvertByteToBinary(result) << setw(5) << (int)result << endl;
   }
   cout << "......................" << endl;       
   cout << endl;

   return 0;
}
