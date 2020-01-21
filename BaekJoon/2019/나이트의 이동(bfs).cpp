#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int v[301][301];
int dx[8] = {-2,-1,1,2,2,1,-1,-2};
int dy[8] = {1,2,2,1,-1,-2,-2,-1};
int l;
int cx, cy, ax, ay;
void bfs()
{
	queue<pair<int, int>> q;
	q.push(make_pair(cx, cy));
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		if (x == ax && y == ay) return;
		for (int i = 0; i < 8; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < l && ny >= 0 && ny < l && !v[nx][ny]) {
				v[nx][ny] = v[x][y] + 1;
				q.push(make_pair(nx, ny));
				if (nx == ax && ny == ay) return;
			}
		}
	}
}
int main()
{
	int T;
	cin >> T;
	while (T--) {
		cin >> l;
		for (int i = 0; i < l; i++) 
			for (int j = 0; j < l; j++) 
				v[i][j] = 0;		
		cin >> cx >> cy >> ax >> ay;
		bfs();
		cout << v[ax][ay] << endl;
	}
}
