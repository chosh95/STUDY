#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    void dfs(int oCnt, int cCnt, int n, string str, vector<string>& ans) {
        if (oCnt == cCnt && cCnt == n) {
            ans.push_back(str);
            return;
        }

        if (oCnt < n)
            dfs(oCnt + 1, cCnt, n, str + "(", ans);

        if (oCnt > cCnt)
            dfs(oCnt, cCnt + 1, n, str + ")", ans);

        return;
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        dfs(0, 0, n, "", ans);
        return ans;
    }
};

int main()
{
    Solution s;
    vector<string> res = s.generateParenthesis(3);
    for (string str : res)
        cout << str << " ";
}