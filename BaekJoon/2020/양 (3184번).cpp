#include <iostream>
#include <queue>
using namespace std;
int R, C;
int visit[251][251];
char p[251][251];
int dx[4] = { -1,0,0,1 };
int dy[4] = { 0,-1,1,0 };
int O, V;

void bfs(int a, int b) {
	queue<pair<int, int>> q;
	q.push({ a,b });
	visit[a][b] = 1;
	int curO = 0, curV = 0;
	if (p[a][b] == 'o') curO++;
	else if (p[a][b] == 'v') curV++;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx<0 || ny <0 || nx>R || ny>C) continue;
			if (p[nx][ny] == '#') continue;
			if (visit[nx][ny] == 1) continue;
			visit[nx][ny] = 1;
			q.push({ nx,ny });
			if (p[nx][ny] == 'o') curO++;
			else if (p[nx][ny] == 'v') curV++;
		}
	}

	if (curO > curV) O += curO;
	else V += curV;
	return;
}

int main()
{
	cin >> R >> C;
	for (int i = 0; i < R; i++) 
		for (int j = 0; j < C; j++) 
			cin >> p[i][j];

	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			if (visit[i][j] == 0 && p[i][j] != '#') bfs(i, j);

	cout << O << " " << V;
}