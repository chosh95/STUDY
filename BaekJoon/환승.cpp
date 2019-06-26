#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int K, N, M;
vector<int> v[100000 + 1000 + 2];
int visit[100000+1000+2];
void bfs()
{
	queue<int> q;
	q.push(1);
	visit[1] = 1;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		if (x == N) {
			cout << visit[x]/2 + 1;
			return;
		}
		for (int i = 0; i < v[x].size(); i++) {
			int nx = v[x][i];
			if (!visit[nx]) {
				visit[nx] = visit[x] + 1;
				q.push(nx);
			}
		}
	}
	cout << "-1";
}

int main()
{
	cin >> N >> K >> M;
	for (int i = 1; i <= M; i++) {
		for (int j = 0; j < K; j++) {
			int node;
			cin >> node;
			v[N + i].push_back(node);
			v[node].push_back(N + i);
		}
	}
	bfs();
}