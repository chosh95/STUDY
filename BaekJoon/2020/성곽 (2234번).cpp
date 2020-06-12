#include <iostream>
#include <queue>
using namespace std;
int N, M;
int visit[51][51]; // 방의 번호 부여
int visit2[51][51]; // 방의 연결 여부를 알기 위한 방문 배열
int p[51][51]; // 맨 처음 입력받는 벽의 정보
int dx[4] = { 0,-1,0,1 }; //서, 북, 동, 남
int dy[4] = { -1,0,1,0 }; 
int binary[4]; // p[i][j]의 벽 정보. 서, 북, 동, 남에 벽이 있으면 1 없으면 0
int roomNumber = 0, maxRoomSize = 0, maxSumSize = 0 ; // 전체 방의 개수, 최대 방의 크기, 최대 합한 방의 크기
int room[2501]; // room[i] : i번째 방의 크기

void bi(int a, int b) {
	int cur = p[a][b];
	int cnt = 0;
	while (cnt<4) {
		binary[cnt] = 0;
		int rest = cur % 2;
		cur /= 2;
		if (rest == 1)
			binary[cnt] = 1;
		cnt++;
	}
}

void bfs(int a, int b) {
	queue<pair<int, int>> q;
	q.push({ a,b });
	visit[a][b] = roomNumber;
	int tmpRoomSize = 1;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		bi(x, y);
		for (int i = 0; i < 4; i++) {
			if (binary[i] == 1) continue;
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx<1 || ny<1 || nx>N || ny>M) continue;
			if (visit[nx][ny] == 0) {
				visit[nx][ny] = roomNumber;
				q.push({ nx,ny });
				tmpRoomSize++;
			}
		}
	}
	room[roomNumber] = tmpRoomSize;
	maxRoomSize = max(maxRoomSize, tmpRoomSize);
}

void bfs2()
{
	visit2[1][1] = 1;
	queue<pair<int, int>> q;
	q.push({1,1});
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		int curRoomNumber = visit[x][y];
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx<1 || ny<1 || nx>N || ny>M) continue;
			if (visit2[nx][ny] == 0) {
				q.push({ nx,ny });
				visit2[nx][ny] = 1;
				int nextRoomNumber = visit[nx][ny];
				if (curRoomNumber != nextRoomNumber) {
					maxSumSize = max(maxSumSize, room[curRoomNumber] + room[nextRoomNumber]);
				}
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> M >> N;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			cin >> p[i][j];

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			if (visit[i][j] == 0) {
				roomNumber++;
				bfs(i, j);
			}

	bfs2();

	cout << roomNumber << "\n";
	cout << maxRoomSize << "\n";
	cout << maxSumSize;
}