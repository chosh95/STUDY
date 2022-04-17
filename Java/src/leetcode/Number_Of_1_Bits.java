package leetcode;

import com.sun.jmx.snmp.SnmpUnsignedInt;

public class Number_Of_1_Bits {
    public static void main(String[] args) {
        System.out.println(hammingWeight(-3));
    }

    public static int hammingWeight(int n) {
        int res = 0;
        while (n != 0) {
            if ((n & 1) == 1) {
                res++;
            }
            // unsigned bit shift 연산자. 요녀석이 핵심
            n = n >>> 1;
        }

        return res;
    }
}
