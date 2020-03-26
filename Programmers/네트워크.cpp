#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;
int visit[201];

void bfs(int a, int n, vector<vector<int>> p) {
	visit[a] = 1;
	queue<int> q;
	q.push(a);

	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int nx = 0; nx < n; nx++) {
			if (x == nx) continue;
			if (p[x][nx] == 0) continue;
			if (visit[nx] == 1) continue;
			visit[nx] = 1;
			q.push(nx);
		}
	}
	return;
}

int solution(int n, vector<vector<int>> computers) {
	int answer = 0;
	for (int i = 0; i < n; i++) {
		if (visit[i] == 0) {
			bfs(i, n, computers);
			answer++;
		}
	}
	return answer;
}

int main()
{
	cout << solution(3, { {1, 1, 0},{1, 1, 0},{0, 0, 1} });
}