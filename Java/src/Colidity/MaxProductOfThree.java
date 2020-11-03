package Colidity;

import java.util.Arrays;

public class MaxProductOfThree {
    class Solution {
        public int solution(int[] A) {
            if(A.length==3) return A[0]*A[1]*A[2];
            Arrays.sort(A);
            int res = -1000 * 1000 * 1000;
            int n = A.length;
            res = Math.min(A[0]*A[1]*A[A.length-1],res);
            res =Math.min(res, A[n-1]*A[n-2]*A[n-3]);
            return res;
        }
    }
}
