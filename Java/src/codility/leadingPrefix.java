package codility;

public class leadingPrefix {
    class Solution {
        public int solution(int[] A) {
            int maxSum = -1; // 합의 최대값
            int curSum = 0; // 현재 합

            for(int x : A){
                if(x < 0)
                    curSum = 0; //합 초기화
                else{
                    curSum += x;
                    maxSum = Math.max(maxSum,curSum);
                }
            }

            return maxSum;
        }
    }
}
