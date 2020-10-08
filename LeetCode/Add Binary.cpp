#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int aIdx = a.size() - 1;
        int bIdx = b.size() - 1;

        string answer = "";

        int carry = 0;
        while (aIdx >= 0 || bIdx >= 0 || carry == 1) {    
            if (aIdx >= 0 && a[aIdx--] == '1') carry += 1;
            if (bIdx >= 0 && b[bIdx--] == '1') carry += 1;

            if (carry % 2 == 0) answer.insert(0, "0");
            else answer.insert(0, "1");

            carry /= 2;
        }

        return answer;
    }
};

int main()
{
    Solution s;
    cout << s.addBinary("110010", "100");
}