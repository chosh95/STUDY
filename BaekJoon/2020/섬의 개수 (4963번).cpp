#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
int w, h;
int p[52][52];
int visit[52][52];
int dx[8] = { -1,-1,0,1,1,1,0,-1 };
int dy[8] = { 0,1,1,1,0,-1,-1,-1 };

void bfs(int a, int b) {
	queue<pair<int, int>> q;
	q.push({ a,b });
	visit[a][b] = 1;

	while(!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 8; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 1 || ny <1 || nx > w || ny > h) continue;
			if (visit[nx][ny]) continue;
			if (p[nx][ny] != 1) continue;
			q.push({ nx,ny });
			visit[nx][ny] = 1;
		}
	}
}


int main()
{
	while (true) {
		cin >> h >> w;
		if (w == 0 && h == 0) return 0;

		memset(p, 0, sizeof(p));
		memset(visit, 0, sizeof(visit));
		for (int i = 1; i <= w; i++)
			for (int j = 1; j <= h; j++)
				cin >> p[i][j];

		int res = 0;
		for (int i = 1; i <= w; i++)
			for (int j = 1; j <= h; j++)
				if (p[i][j] == 1 && visit[i][j] == 0) {
					bfs(i, j);
					res++;
				}

		cout << res << "\n";
	}

}