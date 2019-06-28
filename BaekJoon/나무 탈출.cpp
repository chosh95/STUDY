#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N;
vector<int> list[500001];
int dist[500001];
int res;
void bfs()
{
	queue<int> q;
	q.push(1);
	dist[1] = 0;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		if (list[x].size() == 1 && x != 1) res += dist[x];
		for (int i = 0; i < list[x].size(); i++) {
			int nx = list[x][i];
			if (dist[nx] != 0) continue;
			dist[nx] = dist[x] + 1;
			q.push(nx);
		}
	}
}

int main()
{
	cin >> N;
	int a, b;
	for (int i = 1; i < N; i++) {
		cin >> a >> b;
		list[a].push_back(b);
		list[b].push_back(a);
	}
	bfs();
	if (res % 2 == 0) cout << "No";
	else cout << "Yes";
}