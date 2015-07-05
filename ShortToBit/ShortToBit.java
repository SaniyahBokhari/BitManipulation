/*********************************************************************************
/ Java Program that converts a selection of short values to 16 bit representation. 
/
/*********************************************************************************/

import java.util.Scanner;
import java.io.*;


class ShortToBit{

    public static String ConvertShortToBinary(short short_value){
        String binary_string = "";
        int probe = 0x8000; // Equivalent to 16 bits in binary 
                            // with 1 in the left most position
                            // and zeroes elsewhere
        int result;
        for(int i=0;i<16;i++){ // Probe bit position from left to right
            result = (probe & (int)short_value);
            binary_string += ((result!=0) ? "1" : "0");      
            probe = probe >>> 1; // Shift probe 1 position to the right
                                 // and fill left hand side with zeros
        }
        return binary_string;
    }

    public static void main(String args[]){

       for(short i=0;i<4;i++){ // Print out the 4 smallest values of short in binary
          short value = (short)(Short.MIN_VALUE+i);
          System.out.format("%6d %s\n",value,ConvertShortToBinary(i));
       }
 
       System.out.println();

       for(short i=-4;i<=4;i++){ // Print out values of short in binary from -4 to 4 
          System.out.format("%6d %s\n",i,ConvertShortToBinary(i));
       }

       System.out.println();

       for(short i=3;i>=0;i--){ // Print out the 4 largest values of short in binary
          short value = (short)(Short.MAX_VALUE-i);
          System.out.format("%6d %s\n",value,ConvertShortToBinary(value));

       }
    }
}
