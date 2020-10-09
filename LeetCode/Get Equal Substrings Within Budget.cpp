#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int len = s.size();
        vector<int> diff(len);
        
        for (int i = 0; i < len; i++)
            diff[i] = abs(s[i] - t[i]);

        int maxLength = 0, curCost = 0;
        int left = 0, right = 0;

        while (left <= right && right < len) {
            curCost += diff[right];

            while (curCost > maxCost) {
                curCost -= diff[left++];
            }

            maxLength = max(maxLength, right - left + 1);
            right++;
        }

        return maxLength;
    }
};

int main()
{
    Solution s;
    cout << s.equalSubstring("abcd", "acde", 0);
}