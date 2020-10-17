#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool checkRecord(string s) {
        int aCnt = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'A') {
                if (++aCnt > 1) return false;
            }
            else if (s[i] == 'L' && i < s.size() - 2) {
                if (s[i + 1] == 'L' && s[i + 2] == 'L') return false;
            }
        }

        return true;
    }
};

int main()
{
    Solution s;
    cout << s.checkRecord("PALLPPA");
}