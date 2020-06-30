#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
int dx[4] = { -1,0,0,1 };
int dy[4] = { 0,-1,1,0 };
int p[21][21], dist[21][21]; // 지도, 물고기들의 거리
int minX, minY, minDist; // 가장 가까운 물고기 위치, 거리
int sX, sY, sSize, sEatCnt; // 상어의 위치, 크기, 먹은 수
int N, res; // 지도 크기, 결과값

void bfs(int startX, int startY)
{
	queue<pair<int, int>> q; 
	q.push({ startX,startY }); //큐에 시작점을 넣어주고
	dist[startX][startY] = 0;  //시작위치의 거리를 0으로 세팅

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		if (p[x][y] != 0 && p[x][y] < sSize) { //현재 위치가 물고기가 있고 상어보다 작다면 먹을 수 있다.
			if (minDist > dist[x][y]) //최소 거리보다 더 짧다면 현재 위치를 최소 거리로 최신화
				minX = x, minY = y, minDist = dist[x][y];
			else if (minDist == dist[x][y]) { //거리가 같다면 보다 위에, 보다 왼쪽에 있는 고기로 최신화
				if (minX > x)
					minX = x, minY = y, minDist = dist[x][y];
				else if (minX == x) {
					if(minY > y)
						minX = x, minY = y, minDist = dist[x][y];
				}
			}
		}

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx<1 || ny<1 || nx>N || ny>N) continue; //범위를 넘거나
			if (dist[nx][ny] != -1) continue; //방문한 적이 있거나
			if (p[nx][ny] > sSize) continue; //상어보다 큰 고기는 지나갈 수 없다.
			dist[nx][ny] = dist[x][y] + 1;
			q.push({ nx,ny });
		}
	}
}

int main()
{
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> p[i][j];
			if (p[i][j] == 9) {
				sX = i, sY = j;
				sSize = 2, sEatCnt = 0;
				p[i][j] = 0;
			}
		}
	}

	while (true) {
		memset(dist, -1, sizeof(dist)); //사전 작업, 거리 초기화
		minX = minY = minDist = 9999;  // 최소 좌표, 거리 초기화

		bfs(sX, sY); //상어 위치에서 가장 가까운 위치 구하기

		if (minDist == 9999) break; // 더 먹을 고기가 없으면 끝낸다.

		sX = minX, sY = minY; // 상어 다음 위치
		sEatCnt++; //먹은 고기 양을 늘린다.
		if (sEatCnt == sSize) // 고기 많이 먹으면 크기 늘려주기
			sEatCnt = 0, sSize++;
		p[sX][sY] = 0; // 이 지점을 0 으로
		res += dist[sX][sY]; //거리값을 결과값에 더한다.
	}
	cout << res;
}