/********************************************************************************
/ Java program that converts a selection of byte values to 8 bit representation. 
/
/********************************************************************************/

import java.util.Scanner;
import java.io.*;


class ByteToBit{

    public static String ConvertByteToBinary(byte byte_value){
        String binary_string = "";
        int probe = 0x80; // Equivalent to binary 1000 0000
        int result;
        for(int i=0;i<8;i++){ // Probe bit positions from left to right
            result = (probe & (int)byte_value);
            binary_string += ((result!=0) ? "1" : "0");      
            probe = probe >>> 1; // Shift probe 1 position to the right and 
                                 // fill left hand side with zeros
        }
        return binary_string;
    }

    public static void main(String args[]){
       byte vals[] = new byte[]{0,1,2,64,65,125,126,127,-128,-127,-64,-2,-1};  
       for(byte i=0;i<vals.length;i++){
          System.out.format("%4d %s\n",vals[i],ConvertByteToBinary(vals[i]));
       }
    }
}
