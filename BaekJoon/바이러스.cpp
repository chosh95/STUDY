#include <iostream>
#include <queue>
using namespace std;
queue<pair<int,int>> q;
int p[101][101];
int d[101];
void bfs(int n)
{
	d[q.front().second] = 1;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 1; i <= n; i++) {
			if (p[y][i] == 1 && d[i] == 0) {
				q.push(make_pair(y, i));
				d[i] = 1;
			}
		}
	}
}

int main()
{
	int N, T;
	cin >> N >> T;
	for (int i = 1; i <= T; i++) {
		int a, b;
		cin >> a >> b;
		p[a][b] = p[b][a] = 1;
		if (a == 1 || b == 1) q.push(make_pair(a, b));
	}
	bfs(N);
	int count = 0;
	for (int i = 2; i <= N; i++) if (d[i] == 1) count++;
	cout << count;
}