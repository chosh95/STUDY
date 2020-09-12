#include <string>
#include <queue>
#include <vector>
#include <memory.h>
#include <iostream>
using namespace std;

int p[101][101];
int visit[101];

//wl : win이면 1조사, lose면 -1 조사
int bfs(int idx, int wl, int n) {
    memset(visit, 0, sizeof(visit));
    queue<int> q;
    q.push(idx);
    visit[idx] = 1;

    int cnt = 0;
    while (!q.empty()) {
        int x = q.front();
        q.pop();

        for (int i = 1; i <= n; i++) {
            if (i == idx) continue; // 자신 제외
            if (visit[i] == 1) continue; // 방문한경우 제외
            if (p[x][i] != wl) continue; // 0이거나 wl과 다르면 제외
            q.push(i);
            visit[i] = 1;
            cnt++; // win or lose 사람 수 추가
        }
    }

    return cnt;
}

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    for (int i = 0; i < results.size(); i++) {
        int a = results[i][0], b = results[i][1];
        p[a][b] = 1; // 이김
        p[b][a] = -1; // 짐
    }

    for (int i = 1; i <= n; i++) {
        int cnt = bfs(i, 1, n); // 이긴 사람 계산
        cnt += bfs(i, -1, n); // 진 사람 계산
        if (cnt == n - 1) answer++; // 합해서 n-1이면 자신의 순위를 알 수 있다.
    }

    return answer;
}

int main()
{
    cout << solution(5, { {4,3},{4,2},{3,2},{1,2},{2,5} });
}