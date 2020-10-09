#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>
using namespace std;
int dp[21][2001];

class Solution {
public:
    int len;
    int dfs(vector<int>& nums, int idx, int sum, int S) {
        if (idx == len) {
            if (S== sum) return 1;
            return 0;
        }

        if (dp[idx][sum + 1000] != 0) return dp[idx][sum + 1000];

        dp[idx][sum + 1000] += dfs(nums, idx + 1, sum+ nums[idx], S);
        dp[idx][sum + 1000] += dfs(nums, idx + 1, sum- nums[idx], S);

        return dp[idx][sum + 1000];
    }

    int findTargetSumWays(vector<int>& nums, int S) {
        if (S > 1000) return 0;

        len = nums.size();
        memset(dp, 0, sizeof(dp));

        return dfs(nums, 0,0, S);
    }
};

int main()
{
    Solution s;
    vector<int> input = { 1,1,1,1,1 };
    cout << s.findTargetSumWays(input, 3);
}