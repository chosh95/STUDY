#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>> matrix) {
        if (matrix.empty()) return 0;
        int len1 = matrix.size();
        int len2 = matrix[0].size();
        vector<vector<int>> dp(len1 + 1,vector<int>(len2 + 1,0));

        int answer = 0;
        for (int i = 1; i <= len1; i++) {
            for (int j = 1; j <= len2; j++) {
                if (matrix[i-1][j-1] == '0') continue;
                int next = min(dp[i - 1][j], dp[i][j - 1]);
                next = min(next, dp[i - 1][j - 1]);
                dp[i][j] = next + 1;

                answer = max(answer, dp[i][j]*dp[i][j]);
            }
        }

        return answer; 
    }
};

int main()
{
    Solution s;
    cout << s.maximalSquare({ {'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}});
}