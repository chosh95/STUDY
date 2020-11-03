package Colidity;

import com.sun.org.apache.bcel.internal.generic.ARRAYLENGTH;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class CyclieRotation {
    class Solution {
        public int[] solution(int[] A, int K) {
            if(A.length==0) return A;
            K %= A.length;

            int[] sub = new int[A.length-K];
            System.arraycopy(A,0,sub,0,A.length-K);
            System.arraycopy(A,A.length-K,A,0,K);
            System.arraycopy(sub,0,A,K,A.length-K);

            return A;
        }
    }
}


