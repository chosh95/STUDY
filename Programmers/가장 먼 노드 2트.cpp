#include <string>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
vector<int> v[20001];
int visit[20001];

void bfs() {
    queue<int> q;
    q.push(1);
    visit[1] = 1;

    while (!q.empty()) {
        int x = q.front();
        q.pop();

        for (int i = 0; i < v[x].size(); i++) {
            int nx = v[x][i];
            if (visit[nx] != 0) continue;
            q.push({ nx });
            visit[nx] = visit[x] + 1;
        }
    }
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    for (int i = 0; i < edge.size(); i++) {
        int a = edge[i][0], b = edge[i][1];
        v[a].push_back(b);
        v[b].push_back(a);
    }

    bfs();

    int maxLen = 0;
    for (int i = 1; i <= n; i++) 
        maxLen = max(maxLen, visit[i]);
    for (int i = 1; i <= n; i++)
        if (visit[i] == maxLen) answer++;

    return answer;
}

int main()
{
    cout << solution(6, { {3,6},{4,3},{3,2},{1,3},{1,2},{2,4},{5,2} });
}