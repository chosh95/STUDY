package Colidity;

public class HouseRobberII {
    class Solution {
        int dp[][];

        public int rob(int[] nums) {
            if (nums.length == 0) return 0;
            if (nums.length == 1) return nums[0];

            dp = new int[nums.length][2]; // 0 : 첫날 훔친거, 1 : 첫날 안움친거

            dp[0][0] = nums[0];
            dp[1][0] = Math.max(nums[0], nums[1]);
            dp[0][1] = 0;
            dp[1][1] = nums[1];

            for (int i = 2; i < nums.length; i++) {
                dp[i][0] = Math.max(dp[i - 1][0], dp[i - 2][0] + nums[i]);
                dp[i][1] = Math.max(dp[i - 1][1], dp[i - 2][1] + nums[i]);
            }
            return Math.max(dp[nums.length - 2][0], dp[nums.length - 1][1]);
        }
    }
}
