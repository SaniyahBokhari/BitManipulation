/************************************************************************************************
/ Java program that converts arbitary width data types into appropriate bit representations. 
/
/************************************************************************************************/

import java.util.*;
import java.io.*;
import java.lang.*;


class ArbitraryToBit{

    public static String ConvertToBinary (long value, int size){
        String binary_string = "";

        long probe = 1L << (size-1);
        long result;
        for(int i=0;i<size;i++){ // Probe bit position from left to right
            result = probe & value;
 
            binary_string += (result!=0)?"1":"0";      
            probe = probe >>> 1; // Shift right without extending sign bit
        }
        return binary_string;
    }

    public static void main(String args[]){
       Integer x = 47;
       System.out.println(x.SIZE);
       System.out.println(x.intValue());
       System.out.println(ConvertToBinary(x.intValue(),x.SIZE));
       Byte y = 12;
       System.out.println(y.SIZE);
       System.out.println(y.byteValue());
       System.out.println(ConvertToBinary(y.byteValue(),y.SIZE));
       Long z = 65535L;
       System.out.println(z.SIZE);
       System.out.println(z.longValue());
       System.out.println(ConvertToBinary(z.longValue(),z.SIZE));
     
       int bitSize = 9;  
       for(int i=0;i<(1<<bitSize);i++){
          Integer q = i;
          System.out.format("%10d %s\n",q,ConvertToBinary(q.intValue(),bitSize));
           
       }

    }
}

