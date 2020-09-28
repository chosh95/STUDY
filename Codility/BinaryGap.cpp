#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int solution(int N) {
    string str;
    while (N != 0) {
        if (N % 2 == 0) str.push_back('0');
        else str.push_back('1');
        N /= 2;
    }
    
    bool isOne = false;
    int maxCnt = 0, cnt = 0;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '0' && isOne == false) continue;
        if (str[i] == '1') {
            isOne = true;
            maxCnt = max(maxCnt, cnt);
            cnt = 0;
        }
        else {
            cnt++;
        }
    }
    return maxCnt;
}

int main()
{
    cout << solution(5);
}