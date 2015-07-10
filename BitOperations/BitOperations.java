/*************************************************************************
/ Java program to Demonstrate Bit Operations. 
/
/*************************************************************************/

import java.util.Scanner;
import java.io.*;


class BitOperations{

    public static void printAnswer(byte value1, byte value2, byte result, String operation){
       System.out.println("......................");       
       System.out.println("The "+operation+" operation: ");
       System.out.println("......................");       
       System.out.format("%9s %5d\n",ConvertByteToBinary(value1),value1);
       System.out.format("%6s %7s\n",operation,operation);
       System.out.format("%9s %5d\n",ConvertByteToBinary(value2),value2);
       System.out.format("%6s %7s\n","=","=");
       System.out.format("%9s %5d\n",ConvertByteToBinary(result),result);
       System.out.println("......................");       
       System.out.println();
    }
   
     public static void printAnswer(byte value1, byte result, String operation){
       System.out.println("......................");       
       System.out.println("The "+operation+" operation: ");
       System.out.println("......................");       
       System.out.format("%9s %5d\n",ConvertByteToBinary(value1),value1);
       System.out.format("%6s %7s\n",operation,operation);
       System.out.format("%6s %7s\n","=","=");
       System.out.format("%9s %5d\n",ConvertByteToBinary(result),result);
       System.out.println("......................");       
       System.out.println();
    }

    public static String ConvertByteToBinary(byte integer_value){
       String binary_string = "";
       int probe = 0x80; // Equivalent to 8 bits in binary 
                                // with 1 in the left most position
                                // and zeroes elsewhere

       int result;
       for(int i=0;i<8;i++){ // Probe bit position from left to right
          result = probe & (int)integer_value;
          binary_string+=(result!=0)?"1":"0";
          probe = probe >>> 1;          
       }
       return binary_string;

    }

    public static String ConvertIntToBinary(int integer_value){
        String binary_string = "";
        int probe = 0x80000000; // Equivalent to 32 bits in binary 
                                // with 1 in the left most position
                                // and zeroes elsewhere
        int result;
        for(int i=0;i<32;i++){ // Probe bit position from left to right
            result = probe & integer_value;
            binary_string += (result!=0)?"1":"0";      
            probe = probe >>> 1; // Shift right without extending sign bit
        }
        return binary_string;
    }

    public static void main(String args[]){
       byte val1 = -127;
       byte val2 = 5;
    
       // AND Operation

       byte AndResult = (byte)( (int) val1 & (int)val2 );
       printAnswer(val1,val2,AndResult,"&");

       // OR Operation

       byte OrResult = (byte)( (int) val1 | (int)val2 );
       printAnswer(val1,val2,AndResult,"|");

       // XOR Operation

       byte XorResult = (byte)( (int) val1 ^ (int)val2 );
       printAnswer(val1,val2,AndResult,"^");

       // NOT Operation

       byte NotResult = (byte)(~(int) val1);
       printAnswer(val1,NotResult,"~");

       // Shift Left Operation

       System.out.println("..................................................");       
       System.out.println("The << operation: ");
       System.out.println("..................................................");       
       int result = val2; 
       System.out.format("<< %d %9s %5d\n",0,ConvertIntToBinary(result),result);
       for(int i=0;i<8;i++){
          result = result << 1;
          System.out.format("<< %d %9s %5d\n",i+1,ConvertIntToBinary(result),result);
       }
       System.out.println("..................................................");       
       System.out.println(); 


       // Shift Right Operation

       System.out.println("..................................................");       
       System.out.println("The >> operation: ");
       System.out.println("..................................................");       
       result = val1; 
       System.out.format(">> %d %9s %5d\n",0,ConvertIntToBinary(result),result);
       for(int i=0;i<8;i++){
          result = result >> 1;
          System.out.format(">> %d %9s %5d\n",i+1,ConvertIntToBinary(result),result);
       }
       System.out.println("..................................................");       
       System.out.println(); 
      
       // Shift Right Unsigned Operation

       System.out.println("..................................................");       
       System.out.println("The >>> operation: ");
       System.out.println("..................................................");       
       result = val1; 
       System.out.format(">>> %d %9s %5d\n",0,ConvertIntToBinary(result),result);
       for(int i=0;i<8;i++){
          result =  result >>> 1;
          System.out.format(">>> %d %9s %5d\n",i+1,ConvertIntToBinary(result),result);
       }
       System.out.println("..................................................");       
       System.out.println(); 

    }
}
