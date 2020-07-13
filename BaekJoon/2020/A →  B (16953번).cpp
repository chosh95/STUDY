#include <iostream>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;
int A, B, res = -1;
map<int, int> m;
void bfs()
{
	queue<int> q;
	q.push(A);
	m[A] = 1;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		int cnt = m[cur];
		if (cur > B) continue;
		if (cur == B) {
			res = cnt;
			return;
		}

		if (m[cur * 2] == 0) {
			m[cur * 2] = cnt + 1;
			q.push(cur * 2);
		}
		if (cur >= 100000000) continue;
		int next = cur * 10 + 1;
		if (m[next] == 0) {
			m[next] = cnt + 1;
			q.push(next);
		}
	}
}

int main()
{
	cin >> A >> B;
	bfs();
	cout << res;
}