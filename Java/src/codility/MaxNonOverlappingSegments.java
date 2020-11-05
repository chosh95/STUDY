package codility;

public class MaxNonOverlappingSegments {
    class Solution {

        public int solution(int[] A, int[] B) {
            int curPoint = -1, cnt = 0;
            for(int i=0;i<A.length;i++){
                if(A[i]>curPoint){
                    cnt++;
                    curPoint = B[i];
                }
            }
            return cnt;
        }
    }
}
