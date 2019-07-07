#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <memory.h>
#include <queue>
using namespace std;
int N, M, year, cnt;
int p[302][302]; //녹이기 전 맵
int melt[302][302]; // 녹인 후의 맵
bool visit[302][302]; //방문여부 확인용
int dx[4] = { -1,0,0,1 };
int dy[4] = { 0,-1,1,0 };

//방문하지 않은 빙하의 시작점을 구하는 함수
pair<int, int> pos()
{
	for (int i = 2; i <= N - 1; i++) {
		for (int j = 2; j <= M - 1; j++) {
			if (p[i][j] != 0) return { i,j };
		}
	}
	return { 2,2 };
}
//빙하를 녹이는 함수
void warm()
{
	memset(visit, false, sizeof(visit));
	memset(melt, 0, sizeof(melt));
	pair<int, int> t = pos();
	queue<pair<int, int>> q;
	q.push(t);
	visit[t.first][t.second] = true;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx <= 0 || ny <= 0 || nx > N || ny > M) continue;
			if (!visit[nx][ny] && p[nx][ny] != 0) {
				q.push({ nx,ny });
				visit[nx][ny] = true;
			}
			if (p[nx][ny] == 0) melt[x][y]++;
		}
	}
	for (int i = 2; i <= N - 1; i++) {
		for (int j = 2; j <= M - 1; j++) {
			p[i][j] -= melt[i][j];
			if (p[i][j] < 0) p[i][j] = 0;
		}
	}
}
//빙하의 갯수를 구하는 함수
void bfs(int a,int b)
{
	queue<pair<int, int>> q;
	q.push({ a,b });
	visit[a][b] = true;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (visit[nx][ny] || nx<=0 || ny <=0 || nx>N || ny>M) continue;
			if (p[nx][ny] != 0) {
				q.push({ nx,ny });
				visit[nx][ny] = true;
			}
		}
	}
}

int main()
{
	cin >> N >> M;
	for (int i = 1; i <= N; i++) 
		for (int j = 1; j <= M; j++) 
			scanf("%d", &p[i][j]);
		
	while (true) {
		year++;
		warm();
		cnt = 0;
		memset(visit, false, sizeof(visit));
		for (int i = 2; i <= N - 1; i++) {
			for (int j = 2; j <= M - 1; j++) {
				if (p[i][j] != 0 && visit[i][j] == false) {
					cnt++;
					bfs(i, j);
				}
			}
		}
		if (cnt >= 2){
			cout << year;
			return 0;
		}
		if (cnt == 0) {
			cout << 0;
			return 0;
		}
	}
}
