#include <iostream>
#include <queue>
#include <memory.h>
#include <vector>
using namespace std;
vector < pair<int, int>> v[100001]; // v[i] = j, k  i에서 j 노드 까지 거리 
int visit[100001];
int V, maxnum, maxpos;
void bfs(int num)
{
	memset(visit, -1, sizeof(visit));
	queue<int> q;
	q.push(num);
	visit[num] = 0;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int i = 0; i < v[x].size(); i++) {
			int nx = v[x][i].first;
			int dist = v[x][i].second;
			if (visit[nx] != -1)continue;
			visit[nx] = visit[x] + dist;
			q.push(nx);
			if (visit[nx] > maxnum) {
				maxnum = visit[nx];
				maxpos = nx;
			}
		}
	}
}
int main()
{
	cin >> V;
	int a, b, c;
	for (int i = 1; i <= V; i++) {
		cin >> a >> b;
		while (b != -1) {
			cin >> c;
			v[a].push_back({ b,c });
			cin >> b;
		}
	}
	bfs(1);
	bfs(maxpos);
	cout << maxnum;
}