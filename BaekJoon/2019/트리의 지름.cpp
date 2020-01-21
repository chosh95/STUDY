#include <iostream>
#include <memory.h>
#include <queue>
#include <vector>
using namespace std;
int N;
vector<pair<int,int>> v[10001]; // v[i] = j,k :i에서 j까지 k의 거리
int visit[10001]; //visit[n] : n번 노드까지 길이
int maxpos, maxnum;
void bfs(int num)
{
	memset(visit, -1, sizeof(visit));
	visit[num] = 0;
	queue<int> q;
	q.push(num);
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int i = 0; i < v[x].size(); i++) {
			int nx = v[x][i].first;
			int ncost = v[x][i].second;
			if (visit[nx]!=-1) continue;
			visit[nx] = visit[x] + ncost;
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
	cin >> N;
	int a, b, c;
	for (int i = 1; i < N; i++) {
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}
	bfs(1);
	maxnum = 0;
	bfs(maxpos);
	cout << maxnum;
}