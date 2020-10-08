#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int len;

    void dfs(int i, string s, vector<string> & answer) {
        if (i >= len) {
            answer.push_back(s);
            return;
        }

        dfs(i + 1, s, answer);

        if (s[i] >= '0' && s[i] <= '9') return;
        if (s[i] >= 'a' && s[i] <= 'z') {
            s[i] = s[i] - 'a' + 'A';
            dfs(i+1, s, answer);
        }
        else {
            s[i] = s[i] - 'A' + 'a';
            dfs(i+1, s, answer);
        }
    }

    vector<string> letterCasePermutation(string S) {
        len = S.size();

        vector<string> answer;

        dfs(0, S, answer);

        return answer;
    }
};
