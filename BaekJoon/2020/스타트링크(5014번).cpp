#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int F, S, G, U, D;
int visit[1000001];
int res = 0;

void bfs()
{
	queue<int> q;
	q.push(S);
	memset(visit, -1, sizeof(visit));
	visit[S] = 0;
	
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		if (x == G) {
			res = visit[x];
			return;
		}
		for (int nx : {x + U, x - D}) {
			if (nx<1 || nx>F) continue;
			if (visit[nx] == -1) {
				visit[nx] = visit[x] + 1;
				q.push(nx);
			}
		}
	}
}

int main()
{
	cin >> F >> S >> G >> U >> D;
	bfs();
	if (S == G) {
		cout << 0;
		return 0;
	}
	if (res == 0) cout << "use the stairs";
	else cout << res;
}