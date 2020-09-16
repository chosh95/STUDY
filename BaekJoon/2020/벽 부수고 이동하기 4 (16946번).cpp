#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <memory.h>
#include <map>
#include <string>
using namespace std;

int N, M;
int p[1001][1001]; // 지도
int visit[1001][1001]; // roomSize의 인덱스를 저장하는 배열
vector<int> roomSize; // 각 인덱스가 해당 인덱스가 기록된 visit의 연속된 0의 크기를 저장한다.
int dx[4] = { -1,0,0,1 };
int dy[4] = { 0,-1,1,0 };

void bfs(int a, int b, int c) {
	queue<pair<int, int>> q;
	q.push({ a,b });
	visit[a][b] = c; //시작점을 c 인덱스로 지정

	int curMax = 1; // 현재 연속된 0의 크기
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx<1 || ny<1 || nx>N || ny>M) continue;
			if (p[nx][ny] != 0) continue;			
			if (visit[nx][ny] == -1) {
				q.push({ nx,ny });
				visit[nx][ny] = c;
				curMax++;
			}
		}
	}
	roomSize.push_back(curMax); // 해당 방의 크기를 인덱스에 맞게 기록한다.
}

int main()
{
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		string str;
		cin >> str;
		for (int j = 1; j <= M; j++) {
			p[i][j] = str[j - 1] -'0';
		}
	}

	memset(visit, -1, sizeof(visit)); // 방문 안했으면 -1

	int idx = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (p[i][j] == 0 && visit[i][j] == -1) {
				bfs(i, j, idx++); // 해당 방의 크기를 roomSize[idx]에 기록한다.
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (p[i][j] == 0) { //0이면 바로 출력
				cout << 0;
				continue;
			}

			map<int, int> m; // 근처 방의 인덱스를 저장할 맵
			for (int k = 0; k < 4; k++) {
				int nx = i + dx[k];
				int ny = j + dy[k];
				if (nx<1 || ny<1 || nx>N || ny>M) continue;
				if (p[nx][ny] == 1) continue;
				m[visit[nx][ny]] = 1; // 해당 방의 인덱스를 저장
			}
			int cnt = 1;
			for (auto it = m.begin(); it != m.end(); it++) 
				cnt += roomSize[it->first]; // 방의 크기를 cnt에 추가
			cout << cnt % 10; // 10으로 나눈 나머지를 출력한다.
		}
		cout << "\n";
	}
}