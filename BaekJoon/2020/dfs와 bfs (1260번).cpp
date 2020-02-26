#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;	
int N, M, V;
int map[1002][1002];
vector<int> dfsRes;
vector<int> bfsRes;
int dfsVisit[1002];
int bfsVisit[1002];

void dfs(int idx, int cnt)
{
	if (cnt == N+1) return;

	for (int nx = 1; nx<=N; nx++) {
		if (map[idx][nx] != 1) continue;
		if (dfsVisit[nx]==1) continue;
		else {
			dfsVisit[nx] = 1;
			dfsRes.push_back(nx);
			dfs(nx, cnt + 1);
		}
	}
}

void bfs()
{
	queue<int> q;
	q.push(V);
	bfsRes.push_back(V);
	bfsVisit[V] = 1;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int nx = 1; nx <= N; nx++) {
			if (map[x][nx] != 1) continue;
			if (bfsVisit[nx] == 1) continue;
			else {
				q.push(nx);
				bfsVisit[nx] = 1;
				bfsRes.push_back(nx);
			}
		}
	}
}
int main()
{
	memset(dfsVisit, 0, sizeof(dfsVisit));
	memset(bfsVisit, 0, sizeof(bfsVisit));

	cin >> N >> M >> V;
	for (int a, b, i = 0; i < M; i++) {
		cin >> a >> b;
		map[a][b] = map[b][a] = 1;
	}

	dfsVisit[V] = 1;
	dfsRes.push_back(V);
	dfs(V,1);
	bfs();

	for (int i = 0; i < dfsRes.size(); i++) cout << dfsRes[i] << " ";
	cout << endl;
	for (int i = 0; i < bfsRes.size(); i++) cout << bfsRes[i] << " ";

}