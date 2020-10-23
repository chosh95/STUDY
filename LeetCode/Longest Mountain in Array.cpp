#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int longestMountain(vector<int>& A) {
        vector<int> inc(A.size(), 0);
        vector<int> dec(A.size(), 0);

        for (int i = A.size() - 2; i >= 0; i--) 
            if (A[i] > A[i + 1]) dec[i] = dec[i+1] + 1;
        
        for (int i = 1; i < A.size(); i++) 
            if (A[i] > A[i - 1]) inc[i] = inc[i - 1] + 1;
        
        int res = 0;
        for (int i = 0; i < A.size(); i++)
            if (inc[i] != 0 && dec[i] != 0)
                res = max(res, inc[i] + dec[i] + 1);
        
        
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> inp = { 1,5,7,2,3 };
    cout << s.longestMountain(inp);
}