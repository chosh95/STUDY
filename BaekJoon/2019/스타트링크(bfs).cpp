#include <iostream>
#include <queue>
#include <memory.h>
using namespace std;
int F, S, G, U, D;
int p[1000000 + 1];
int res = -1;
void bfs()
{
	memset(p, -1, sizeof(p));
	p[S] = 0;
	queue<int> q;
	q.push(S);
	if (S == G) {
		res = 0;
		return;
	}
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		
		int nx = x + U;
		if (nx == G) {
			res = p[x] + 1;
			return;
		}
		if (nx <= F && p[nx] == -1) {
			q.push(nx);
			p[nx] = p[x] + 1;
		}
		nx = x - D;
		if (nx == G) {
			res = p[x] + 1;
			return;
		}
		if (nx >= 1 && p[nx] == -1) {
			q.push(nx);
			p[nx] = p[x] + 1;
		}
	}
}


int main()
{
	cin >> F >> S >> G >> U >> D;
	bfs();
	if (res == -1) cout << "use the stairs";
	else cout << res;
	return 0;
}