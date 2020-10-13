#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int, int> m;
        for (int x : nums)
            m[x]++;

        for (auto it : m)
            if (it.second == 1) return it.first;

        return 0;
    }
};

int main()
{
    vector<int> inp = { 0,1,0,1,0,1,99 };
    Solution s;
    cout << s.singleNumber(inp);
}