package Colidity;

public class FrogRiverOne {
    class Solution {
        public int solution(int X, int[] A) {
            boolean[] p = new boolean[X];

            int cnt = 0;
            for(int i = 0; i< A.length;i++){
                if(p[A[i]-1]) continue;
                else{
                    p[A[i]-1] = true;
                    cnt++;
                    if(cnt==X) return i;
                }
            }

            return -1;
        }
    }
}
