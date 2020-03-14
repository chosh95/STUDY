#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
int S, res;
int visit[1001][1001];

void bfs()
{
	memset(visit, -1, sizeof(visit));
	visit[1][0] = 0;
	queue<pair<int, int>> q;
	q.push({ 1,0 });

	while (!q.empty()) {
		int x = q.front().first;
		int clip = q.front().second;
		int time = visit[x][clip];
		q.pop();
		if (x == S) {
			res = min(res, time);
			continue;
		}
		//1.화면에 있는 이모티콘을 클립보드에 복사.
		if (visit[x][x] == -1) {
			visit[x][x] = time + 1;
			q.push({ x, x });
		}
		//2.클립보드의 모든 이모티콘을 화면에 복사.
		if (x+clip <=S && visit[x + clip][clip] == -1) {
			q.push({ x + clip,clip });
			visit[x + clip][clip] = time + 1;
		}
		//3.이모티콘을 하나 삭제
		if (x-1 >= 0 && visit[x - 1][clip] == -1) {
			visit[x - 1][clip] = time + 1;
			q.push({ x - 1,clip });
		}
	}
}

int main()
{
	cin >> S;
	res = 9999;

	bfs();

	cout << res;
}