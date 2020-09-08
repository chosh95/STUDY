#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
int visit[201];


void bfs(int start, vector<vector<int>> computers) {
    queue<int> q;
    q.push(start);
    visit[start] = 1;
    
    while (!q.empty()) {
        int x = q.front();
        q.pop();

        for (int i = 0; i < computers[x].size(); i++) {
            if (computers[x][i] == 0) continue;
            if (visit[i] == 1) continue;
            visit[i] = 1;
            q.push(i);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    for (int i = 0; i < n; i++) 
        if (visit[i] == 0) {
            bfs(i, computers);
            answer++;
        }

    return answer;
}

int main()
{
    cout << solution(3, { {1,1,0},{1,1,0},{0,0,1} });
}