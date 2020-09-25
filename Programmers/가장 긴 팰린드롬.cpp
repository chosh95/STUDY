#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


int solution(string s)
{
    for (int i = s.size(); i >= 1; i--) {
        for (int j = 0; j + i <= s.size(); j++) {
            bool isTrue = true;
            for (int k = 0; k <= i / 2; k++) {
                if (s[j + k] != s[j + i - 1 - k]) {
                    isTrue = false;
                    break;
                }
            }
            if (isTrue) return i;
        }
    }
    
    return 1;
}

int main()
{
    cout << solution("abacde");
}