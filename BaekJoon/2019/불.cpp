#include <iostream>
#include <memory.h>
#include <queue>
using namespace std;
char p[1001][1001];
int w, h, res, ax, ay;
int visit[1001][1001];
int fvisit[1001][1001]; // ���� ������ �ð� ����
int dx[4] = { -1,0,0,1 };
int dy[4] = { 0,-1,1,0 };
queue < pair<int, int>> f; // ���� ��ġ�� �����ϴ� ť
void bfs()
{
	queue<pair<int, int>> q;
	q.push({ ax,ay });
	visit[ax][ay] = 1;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		if (x == 1 || y == 1 || x == w || y == h) {
			res = visit[x][y];
			return;
		}
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (p[nx][ny] != '.') continue;
			if (nx < 1 || ny <1 || nx>w || ny > h) continue;
			if (visit[nx][ny] != -1) continue;
			if (fvisit[nx][ny] != -1 && fvisit[nx][ny] <= visit[x][y] + 1) continue;
			visit[nx][ny] = visit[x][y] + 1;
			q.push({ nx,ny });
		}
	}
}
void fire()
{
	while (!f.empty()) {
		int x = f.front().first;
		int y = f.front().second;
		f.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 1 || ny <1 || nx>w || ny > h) continue;
			if (fvisit[nx][ny]!=-1) continue;
			if (p[nx][ny] == '.') {
				f.push({ nx,ny });
				fvisit[nx][ny] = fvisit[x][y] + 1;
			}
		}
	}
}

int main()
{
	int T;
	cin >> T;
	while (T--) {
		res = -1;
		cin >> h >> w;
		while (!f.empty()) f.pop(); // ���� �ʱ� ��ġ �����ϴ� f �ʱ�ȭ
		memset(fvisit, -1, sizeof(fvisit)); // fvisit �ʱ�ȭ
		memset(visit, -1, sizeof(visit)); // visit �ʱ�ȭ
		for (int i = 1; i <= w; i++) {
			for (int j = 1; j <= h; j++) {
				cin >> p[i][j];
				if (p[i][j] == '@') {
					ax = i, ay = j;
				}
				if (p[i][j] == '*') {
					f.push({ i,j });
					fvisit[i][j] = 1;
				}
			}
		}
		fire();
		bfs();
		if (res == -1)cout << "IMPOSSIBLE\n";
		else cout << res << "\n";
	}
}