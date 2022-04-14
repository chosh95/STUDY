package leetcode;

public class Best_Time_to_Buy_and_Sell_Stock {
    public static void main(String[] args) {
        System.out.println(maxProfit(new int[]{1, 2}));
    }

    public static int maxProfit(int[] prices) {
        int maxProfit = 0;
        int curMinPrice = 99999;
        int curProfit = 0;

        for (int i = 0; i < prices.length; i++) {
            if (prices[i] < curMinPrice) {
                curMinPrice = prices[i];
            }
            curProfit = Math.max(curProfit, prices[i] - curMinPrice);
            maxProfit = Math.max(maxProfit, curProfit);
        }

        return maxProfit;
    }
}
