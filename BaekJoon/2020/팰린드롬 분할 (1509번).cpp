#include <iostream>
#include <memory.h>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;
string origin;
bool dp[2501][2501];
int visit[2501];
int n, answer = 5000;

void bfs() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({ 0,0 });
    for (int i = 0; i < n; i++) visit[i] = 5000; 

    while (!q.empty()) {
        int cnt = q.top().first;
        int pos = q.top().second;
        q.pop();

        if (pos == n) {
            answer = min(answer, cnt);
            continue;
        }
        if (visit[pos] <= cnt) continue;
        visit[pos] = cnt;

        for (int i = pos; i < n; i++) {
            if (dp[pos][i])
                q.push({ cnt + 1,i + 1 });
        }
    }

}

int main()
{
    cin >> origin;
    n = origin.size();
    memset(dp, false, sizeof(dp));

    for (int i = 0; i < n; i++) {
        dp[i][i] = true;
        if (i == n - 1) break;
        if (origin[i] == origin[i + 1]) dp[i][i + 1] = true;
    }

    for (int i = 2; i < n; i++)
        for (int j = 0; j + i < n; j++)
            if (origin[j] == origin[j + i] && dp[j + 1][j + i - 1])
                dp[j][j + i] = true;

    bfs();

    cout << answer;
}