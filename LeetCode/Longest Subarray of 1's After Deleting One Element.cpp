#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int answer = 0, cnt = 0, prevCnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) cnt++;
            else {
                answer = max(answer, prevCnt + cnt);
                prevCnt = cnt;
                cnt = 0;
            }
        }
        answer = max(answer, prevCnt + cnt);

        if (answer == nums.size()) return answer - 1;
        return answer;
    }
};

int main()
{
    Solution s;
    vector<int> res = {1,1,0};
    cout << s.longestSubarray(res);
}