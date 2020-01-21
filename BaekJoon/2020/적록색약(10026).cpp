#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
int N;
char p[101][101];
int visit[101][101];
int dx[4] = { -1,0,0,1 };
int dy[4] = { 0,-1,1,0 };

void bfs(int a,int b, int idx)
{
	queue<pair<int, int>> q;
	q.push({ a,b });
	visit[a][b] = idx;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx<1 || ny<1 || nx>N || ny>N) continue;
			if (visit[nx][ny] != -1) continue;
			if (p[nx][ny] != p[x][y]) continue;
			visit[nx][ny] = visit[x][y];
			q.push({ nx,ny });			
		}
	}
}
void bfs2(int a, int b, int idx)
{
	queue<pair<int, int>> q;
	q.push({ a,b });
	visit[a][b] = idx;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx<1 || ny<1 || nx>N || ny>N) continue;
			if (visit[nx][ny] != -1) continue;
			if (p[nx][ny] != p[x][y]) {
				if (p[x][y] == 'B' || p[nx][ny] == 'B')
					continue;
			}
			visit[nx][ny] = visit[x][y];
			q.push({ nx,ny });
		}
	}
}
int main()
{
	cin >> N;
	memset(visit, -1, sizeof(visit));
	for (int i = 1; i <= N; i++) 
		for (int j = 1; j <= N; j++) 
			cin >> p[i][j];

	int idx = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if(visit[i][j]==-1) bfs(i, j, idx++);
		}
	}
	cout << idx <<" ";

	memset(visit, -1, sizeof(visit));
	idx = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (visit[i][j] == -1) bfs2(i, j, idx++);
		}
	}
	cout << idx;
}