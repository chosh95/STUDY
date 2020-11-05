package codility;

public class MaximumPointsYouCanObtainfromCards {

    class Solution {
        int dp[];

        public int maxScore(int[] cardPoints, int k) {
            dp = new int[cardPoints.length+1];
            for(int i = 1;i<=cardPoints.length;i++)
                dp[i] = dp[i-1] + cardPoints[i-1];

            int res = 0;
            for(int i=0;i<=k;i++){
                int tmp = dp[i];
                tmp += dp[cardPoints.length] - dp[cardPoints.length - k + i];
                res = Math.max(res,tmp);
            }
            return res;
        }
    }
}
