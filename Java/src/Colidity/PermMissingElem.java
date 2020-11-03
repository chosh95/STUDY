package Colidity;

import java.util.Arrays;

public class PermMissingElem {
    class Solution {
        public int solution(int[] A) {
            Arrays.sort(A);

            for(int i=0;i<A.length;i++){
                if(A[i] != i+1) return i+1;
            }
            return A.length+1;
        }
    }
}
