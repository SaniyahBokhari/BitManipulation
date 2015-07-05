/*************************************************************************
/ Java program to read an int and convert into bit representation 
/
/
/ from the standard input
/ or
/ redirect from file
/*************************************************************************/

import java.util.Scanner;
import java.io.*;


class IntToBit{

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
       Scanner scan = new Scanner(System.in);

       System.out.print("Enter an integer value: ");
       while(scan.hasNextLine()){
          String integer_string = scan.nextLine();
          int integer_value = Integer.parseInt(integer_string);
          System.out.print("The binary representation is: ");
          String binary_string = ConvertIntToBinary(integer_value);
          System.out.println(binary_string);
          System.out.print("Enter an integer value: ");
       }
    }
}
