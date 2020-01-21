#include <iostream>
#include <queue>
#include <algorithm>
#include <memory.h>
using namespace std;
int visit[1001][1001];
int N; //최대 좌표값
int ba, bb, da, db, ja, jb; //베시, 데이지, 존의 좌표
int bres, dres; // 베시와 데이지의 결과값
int bx[8] = { -1,0,1,1,1,0,-1,-1 };
int by[8] = { 1,1,1,0,-1,-1,-1,0 };
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

void bbfs() //베시의 최단거리 계산용
{
	queue<pair<int, int>> q;
	q.push({ ba,bb });
	visit[ba][bb] = 0;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		if (x == ja && y == jb) {
			bres = visit[x][y];
			return;
		}
		q.pop();
		for (int i = 0; i < 8; i++) {
			int nx = x + bx[i];
			int ny = y + by[i];
			if (nx < 1 || ny < 1 || nx>N || ny >N) continue;
			if (visit[nx][ny] != -1) continue;
			q.push({ nx,ny });
			visit[nx][ny] = visit[x][y] + 1;			
		}
	}
}
void dbfs() //베시의 최단거리 계산용
{
	queue<pair<int, int>> q;
	q.push({ da,db });
	visit[da][db] = 0;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		if (x == ja && y == jb) {
			dres = visit[x][y];
			return;
		}
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 1 || ny < 1 || nx>N || ny >N) continue;
			if (visit[nx][ny] != -1) continue;
			q.push({ nx,ny });
			visit[nx][ny] = visit[x][y] + 1;
		}
	}
}

int main()
{
	cin >> ba >> bb >> da >> db >> ja >> jb;
	N = max(max(max(max(max(ba, bb), da), db), ja), jb);
	memset(visit, -1, sizeof(visit));
	bbfs();
	memset(visit, -1, sizeof(visit));
	dbfs();
	if (bres < dres) cout << "bessie";
	else if (bres == dres) cout << "tie";
	else cout << "daisy";
	return 0;
}