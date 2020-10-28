#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

bool cmp(string a, string b) {
    return a + b > b + a;
}

class Solution {
public:

    string largestNumber(vector<int>& nums) {
        vector<string> v;
        for (int x : nums)
            v.push_back(to_string(x));
        sort(v.begin(), v.end(), cmp);

        string res;
        for (string str : v)
            res += str;

        return res;
    }
};

int main()
{
    Solution s;
    vector<int> input = { 2,10 };
    cout << s.largestNumber(input);
}