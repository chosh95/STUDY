package codility;

public class TieRpoes {
    class Solution {
        public int solution(int K, int[] A) {
            int cnt = 0, curSum = 0 ;
            for(int i=0;i<A.length;i++){
                curSum += A[i];
                if(curSum >= K){
                    curSum = 0;
                    cnt++;
                }
            }
            return cnt;
        }
    }
}
