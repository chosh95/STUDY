#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
int N, M;
vector<int> v[502];
int visit[502];

void bfs()
{
	visit[1] = 1;
	queue<int> q;
	q.push(1);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int i = 0; i < v[cur].size(); i++) {
			int next = v[cur][i];
			if (visit[next] > visit[cur] + 1) {
				visit[next] = visit[cur] + 1;
				q.push(next);
			}
		}
	}
}

int main()
{
	cin >> N >> M;
	for (int i = 0; i <= N; i++) visit[i] = 5;
	for (int a, b, i = 0; i < M; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	bfs();

	int res = 0;
	for (int i = 2; i <= N; i++) {
		if (visit[i] <= 3) res++;
	}
	cout << res;
}