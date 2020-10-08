#include <iostream>
#include <memory.h>
#include <algorithm>
#include <string>
using namespace std;
char p[1001][1001];
int dx[2] = { 1,-1 }; //아래방향 , 대각선 위 방향 이동 좌표
int dy[2] = { 0,1 };

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;

        memset(p, ' ', sizeof(p));

        int dir = 0, x = 0, y = 0;
        for (int i = 0; i < s.size(); i++) {
            if (x == numRows - 1) dir = 1;
            else if (x == 0) dir = 0;

            p[x][y] = s[i];

            x += dx[dir];
            y += dy[dir];

        }

        string answer = "";
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < 1000; j++) {
                if (p[i][j] != ' ') answer += p[i][j];
            }
        }

        return answer;
    }
};

int main()
{
    Solution s;
    cout << s.convert("AB", 1);
}