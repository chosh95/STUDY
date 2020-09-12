#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int p[101][101];

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    for (int i = 0; i < results.size(); i++) {
        int a = results[i][0], b = results[i][1];
        p[a][b] = 1;
        p[b][a] = -1;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                if (p[j][i] == 1 && p[i][k] == 1) p[j][k] = 1;
                if (p[j][i] == -1 && p[i][k] == -1) p[j][k] = -1;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        int cnt = 0;
        for (int j = 1; j <= n; j++) {
            if (p[i][j] != 0) cnt++;
        }
        if (cnt == n - 1) answer++;
    }

    return answer;
}

int main()
{
    cout << solution(5, { {4,3},{4,2},{3,2},{1,2},{2,5} });
}