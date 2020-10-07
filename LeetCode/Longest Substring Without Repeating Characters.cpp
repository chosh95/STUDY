#include <string>
#include <set>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0, right = 0;
        int stringLength = s.size();
        int answer = 0;
        set<char> stringSet;
        while (left < stringLength && right < stringLength) {
            if (stringSet.find(s[right]) == stringSet.end()) {
                stringSet.insert(s[right++]);
                answer = max(answer, right - left);
            }
            else {
                stringSet.erase(s[left++]);
            }
        }
        return answer;
    }
};