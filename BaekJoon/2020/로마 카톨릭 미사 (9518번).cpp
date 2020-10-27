#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
using namespace std;

int R, S, res;
int hand[51][51][51][51]; // (a,b) - (x,y)의 악수 여부 기록
int visit[51][51]; // (a,b)를 조사했는가. 조사 여부와 악수 여부는 다르다.
int p[51][51]; // 좌석 기록
int dx[8] = { -1,0,1,1,1,0,-1,-1 }; // 8가지 방향
int dy[8] = { 1,1,1,0,-1,-1,-1,0 };

void bfs(int a, int b)
{
	queue<pair<int, int>> q;
	q.push({ a,b });
	visit[a][b] = 1;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		visit[x][y] = 1; 

		for (int i = 0; i < 8; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 1 || ny< 1 || nx > R || ny > S) continue;
			if (p[nx][ny] == 0) continue; //빈 좌석이면 건너뜀
			if (hand[x][y][nx][ny] == 1) continue; //악수 했으면 건너뜀
			q.push({ nx,ny });
			hand[x][y][nx][ny] = hand[nx][ny][x][y] = 1;
			res++; //악수 횟수 추가
		}
	}
}

int main()
{
	cin >> R >> S;
	string str;
	for (int i = 1; i <= R; i++) {
		cin >> str;
		for (int j = 1; j <= S; j++) {
			if (str[j - 1] == '.') p[i][j] = 0;
			else p[i][j] = 1;
		}
	}

	for (int i = 1; i <= R; i++) 
		for (int j = 1; j <= S; j++) 
			if (visit[i][j] == 0 && p[i][j] == 1) 
				bfs(i, j); // (i, j) 조사. 상근이 없이 최대 몇 번 악수하는지 조사

	int maxNum = 0; // 상근이가 악수할 최대 회수 기록
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= S; j++) {
			if (p[i][j] == 1) continue; // 빈좌석만 앉아야 한다.
			int cur = 0;
			for (int k = 0; k < 8; k++) {
				int nx = i + dx[k];
				int ny = j + dy[k];
				if (nx<1 || ny<1 || nx>R || ny>S) continue;
				if (p[nx][ny] == 1) cur++; // 악수 회수 추가
			}
			maxNum = max(maxNum, cur);
		}
	}

	cout << res + maxNum; // 상근이 없이 악수하는 횟수 + 상근이가 추가 됐을 때 추가 악수 횟수
}