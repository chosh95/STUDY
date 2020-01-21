#include <iostream>
#include <queue>
#include <memory.h>
using namespace std;
int N;
int p[126][126], visit[126][126];
int dx[4] = { -1, 0, 0,1 };
int dy[4] = { 0, -1, 1,0 };
struct node {
	int x, y, cost;
	bool operator <(node tmp) const { return cost > tmp.cost; }
};
void dijkstra()
{
	priority_queue<node> pq;
	pq.push({ 1,1,p[1][1] });
	visit[1][1] = p[1][1];
	while (!pq.empty()) {
		node cur = pq.top();
		pq.pop();
		for (int i = 0; i < 4; i++) {
			int nx = cur.x + dx[i];
			int ny = cur.y + dy[i];
			if (nx<1 || ny <1 || nx>N || ny>N) continue;
			if (visit[nx][ny] > visit[cur.x][cur.y] + p[nx][ny]) {
				visit[nx][ny] = visit[cur.x][cur.y] + p[nx][ny];
				pq.push({ nx,ny,visit[nx][ny] });
			}
		}
	}
}

int main()
{
	int cnt = 1;
	while (true) {
		cin >> N;
		if (N == 0) return 0;
		memset(p, 0, sizeof(p));
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++) {
				cin >> p[i][j];
				visit[i][j] = 1e9;
			}
		dijkstra();
		cout << "Problem " << cnt++ << ": " << visit[N][N] << "\n";
	}
	return 0;
}