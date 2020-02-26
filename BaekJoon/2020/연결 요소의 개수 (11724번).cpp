#include <iostream>
#include <queue>
#include <vector>
using namespace std;
vector<int> map[1001];
int N, M;
int visit[1001];

void bfs(int start)
{
	queue<int> q;
	q.push(start);
	visit[start] = 1;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int i = 0; i < map[x].size(); i++) {
			int nx = map[x][i];
			if (visit[nx] == 1) continue;
			q.push(nx);
			visit[nx] = 1;
		}
	}
}

int main()
{
	cin >> N >> M;
	for (int a, b, i = 0; i < M; i++) {
		cin >> a >> b;
		map[a].push_back(b);
		map[b].push_back(a);
	}
	int res = 0;
	for (int i = 1; i <= N; i++) {
		if (!visit[i]) {
			bfs(i);
			res++;
		}
	}
	cout << res;
}