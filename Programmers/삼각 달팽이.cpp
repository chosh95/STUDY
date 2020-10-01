#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int p[1001][1001];
vector<int> solution(int n) {
    vector<int> answer;
    int x = 1, y = 1, dir = 0, num = 1;

    for (int i = 0; i < n; i++) {
        if (dir == 0) {
            while(x<=n && y<=n && p[x][y]==0)
                p[x++][y] = num++;
            x--;
            y++;
            dir = 1;
        }
        else if (dir == 1) {
            while (x <= n && y <= n && p[x][y] == 0)
                p[x][y++] = num++;
            x--; y--; y--;
            dir = 2;
            
        }
        else if (dir == 2) {
            while (x <= n && y <= n && p[x][y] == 0)
                p[x--][y--] = num++;
            x++; x++;
            y++;
            dir = 0;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            answer.push_back(p[i][j]);
        }
    }

    return answer;
}

int main()
{
    vector<int> res = solution(4);
    for (int i : res) {
        cout << i << " ";
    }
}