package codility;

public class LongestPalindromicSubstring {
    class Solution {
        boolean dp[][];

        public String longestPalindrome(String s) {
            int N = s.length();
            dp = new boolean[N][N];
            for(int i=0;i<N;i++) {
                dp[i][i] = true;
                if(i != N-1 && s.charAt(i) == s.charAt(i+1))
                    dp[i][i+1] =true;
            }

            for(int i=2;i<N;i++){
                for(int j=0;j+i<N;j++){
                    if(s.charAt(j)==s.charAt(j+i) && dp[j+1][j+i-1])
                        dp[j][j+i] = true;
                }
            }

            String res = "";
            for(int i=0;i<N;i++){
                for(int j=0;j+i<N;j++){
                    if(dp[j][j+i] && res.length()<i)
                        res = s.substring(j,j+i+1);
                }
            }
            return res;
        }
    }
}
