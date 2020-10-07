#include <string>
#include <iostream>
#include <memory.h>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";
        int n = s.length();
        int dp[1001][1001];
        memset(dp, false, sizeof(dp));

        int start = 0, end = 0;

        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
            if (i == n - 1) break;
            if (s[i] == s[i + 1]) {
                dp[i][i + 1] = true;
                start = i, end = i + 1;
            }
        }

        
        for (int i = 3; i <= n; i++) {
            for (int j = 0; j + i - 1 < n; j++) {
                if (s[j] == s[j + i - 1] && dp[j + 1][j + i - 2]) {
                    start = j, end = j + i - 1;
                    dp[j][j + i - 1] = true;
                }
            }
        }
        return s.substr(start, end - start + 1);
    }
};

int main()
{
    Solution s;
    cout << s.longestPalindrome("aacabdkacaa");
}