#include <iostream>
#include <queue>
using namespace std;
int n, a, b;
int res = 9999;
int visit[610];

void bfs()
{
	queue<pair<pair<int, int>, int>> q;
	q.push({ { 0,0 }, 0 });
	visit[0] = 0;
	while (!q.empty()) {
		int x = q.front().first.first;
		int doubleCnt = q.front().first.second;
		int turn = q.front().second;
		q.pop();
		if (x >= n) {
			if (turn < res) res = turn;
			return;
		}
		int nx = x + a;
		if (visit[nx] < turn + 1 && nx < n + a) {
			visit[nx] = turn + 1;
			q.push({ { nx,doubleCnt },turn + 1 });
		}
		nx = x + b;
		if (visit[nx] < turn + 1 && nx < n + a) {
			visit[nx] = turn + 1;
			q.push({ { nx,doubleCnt },turn + 1 });
		}
		if (turn + 1 < 10 * (doubleCnt + 1)) continue;
		nx = x * 2;
		if (visit[nx] < turn + 1 && nx < n + a) {
			visit[nx] = turn + 1;
			q.push({ { nx,doubleCnt + 1 }, turn + 1 });
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cin >> n >> a >> b;
	bfs();
	cout << res;
}