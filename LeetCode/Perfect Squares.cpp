#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> dp;

    int dfs(int cur, int n) {
        if (cur == n) return 0;

        if (dp[cur] != 0) return dp[cur];

        int res = 987654321;
        for (int i = 1; cur + i * i <= n; i++) {
            int next = cur + i * i;
            res = min(res, dfs(next, n) + 1);
        }

        return dp[cur] = res;
    }

    int numSquares(int n) {
        dp.resize(n + 1,0);
        dfs(0, n);
        return dp[0];
    }
};

int main()
{
    Solution s;
    cout << s.numSquares(12);
}