#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
using namespace std;
int T, N, M;
bool isTrue;
int visit[20002];
vector<int> map[20002];

void bfs(int start) {
	queue<int> q;
	q.push(start);
	visit[start] = 1;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int i = 0; i < map[x].size(); i++) {
			int nx = map[x][i];
			if (visit[nx] == 0) {
				q.push(nx);
				visit[nx] = 3 - visit[x];
			}
			else if (visit[nx] == visit[x] && visit[nx] != 0) {
				isTrue = false;
				return;
			}
		}
	}
}

int main()
{
	cin >> T;
	while (T--) {
		cin >> N >> M;

		isTrue = true;
		memset(visit, 0, sizeof(visit));
		memset(map, 0, sizeof(map));

		for (int a, b, i = 0; i < M; i++) {
			cin >> a >> b;
			map[a].push_back(b);
			map[b].push_back(a);
		}

		for (int i = 1; i <= N; i++) {
			if (visit[i] == 0)
				bfs(i);
			if (!isTrue) break;
		}
		
		if (isTrue)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}