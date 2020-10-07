#include <string>
#include <iostream>
#include <memory.h>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";

        bool dp[1001][1001];
        memset(dp, false, sizeof(dp));

        string answer = "";

        for (int i = 0; i < s.size(); i++) {
            dp[i][i] = true;
            if (answer.empty()) answer = s.substr(i, 1);
            if (i == s.size() - 1) break;
            if (s[i] == s[i + 1]) {
                dp[i][i + 1] = true;
                if (answer.length() < 2) answer = s.substr(i, 2);
            }
        }

        for (int i = 2; i < s.size(); i++)
            for (int j = 0; j + i < s.size(); j++)
                if (s[j] == s[j + i] && dp[j + 1][j + i - 1]) {
                    dp[j][j + i] = true;
                    if (answer.length() < i + 1) {
                        answer = s.substr(j, i + 1);
                    }
                }


        return answer;
    }
};

int main()
{
    Solution s;
    cout << s.longestPalindrome("cbbd");
}