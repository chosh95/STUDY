#include <iostream>
#include <queue>
using namespace std;
int F, S, G, U, D;
int visit[1000001];
void bfs()
{
	visit[S] = 1;
	queue<int> q;
	q.push(S);
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int nx : {x + U, x - D}) {
			if (nx<1 || nx > F) continue;
			if (visit[nx] != 0) continue;
			visit[nx] = visit[x] + 1;
			q.push(nx);
		}
	}
}
int main()
{
	cin >> F >> S >> G >> U >> D;

	bfs();

	if (visit[G] == 0) cout << "use the stairs";
	else cout << visit[G] - 1;
}