#include <iostream>
#include <queue>
using namespace std;
int c;
int p[1001][1001];
int v[1001];
queue<pair<int, int>> q;
void bfs(int n)
{
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		if (v[x] == 0 && v[y] == 0) c += 1;
		for (int i = 1; i <= n; i++) {
			if (v[i] == 0 && p[y][i] == 1) {
				v[i] = 1;
				q.push(make_pair(y, i));
			}
		}
	}
}

int main()
{
	int N, M;
	cin >> N >> M;
	bool tmp = false;
	for (int i = 1; i <= M; i++) {
		int a, b;
		cin >> a >> b;
		p[a][b] = p[b][a] = 1;
		if (!tmp) {
			q.push(make_pair(a, b));
			v[a] = v[b] = 1;
			c = 1;
			tmp = true;
		}
		else q.push(make_pair(a, b));
	}
	bfs(N);
	for (int i = 1; i <= N; i++) if (!v[i]) c++;
	cout << c;
}