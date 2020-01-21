#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N, A, B, T;
vector<int> v[101];
int p[101];
void bfs()
{
	queue<int> q;
	q.push(A);
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		if (x == B) {
			cout << p[B];
			return;
		}
		for (int i = 0; i < v[x].size(); i++) {
			int nx = v[x][i];
			if (p[nx] == 0) {
				q.push(nx);
				p[nx] = p[x] + 1;
			}
		}
	}
	cout << -1;
}

int main()
{
	cin >> N >> A >> B >> T;
	while (T--) {
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	bfs();
	return 0;
}