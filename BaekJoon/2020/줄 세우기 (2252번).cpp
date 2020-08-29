#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
vector<int> v[32001];
int deg[32001];

void bfs() {
	queue<int> q;
	for (int i = 1; i <= N; i++)
		if (deg[i] == 0) q.push(i);

	while (!q.empty()) {
		int x = q.front();
		q.pop();

		cout << x << " ";

		for (int i = 0; i < v[x].size(); i++) {
			int nx = v[x][i];
			if (--deg[nx] == 0)
				q.push(nx);
		}
	}
}

int main()
{
	cin >> N >> M;
	for (int a, b, i = 1; i <= M; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		deg[b]++;
	}

	bfs();
}