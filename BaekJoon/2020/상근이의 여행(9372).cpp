#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
int C, N, M, res;
vector<int> v[1001];
bool visit[1001];

void bfs()
{
	queue<int> q;
	q.push(1);
	visit[1] = true;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int i = 0; i < v[x].size(); i++) {
			int nx = v[x][i];
			if (visit[nx]) continue;
			q.push(nx);
			visit[nx] = true;
			res++;
		}
	}
}

int main()
{
	cin >> C;
	while (C--) {
		cin >> N >> M;
		res = 0;
		for (int i = 0; i < 1001; i++) v[i].clear();
		memset(visit, false, sizeof(visit));

		for (int a, b, i = 0; i < M; i++) {
			cin >> a >> b;
			v[a].push_back(b);
			v[b].push_back(a);
		}
		bfs();
		cout << res << "\n";
	}
}