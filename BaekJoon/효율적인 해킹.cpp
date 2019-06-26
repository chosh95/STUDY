#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int p[10001];
vector<int> list[10001];
int N, M, res, idx;
void bfs(int t)
{
	queue<int> q;
	q.push(t);
	int visit[10001] = {};
	visit[t] = 1;
	int cnt = 1;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int i = 0; i < list[x].size(); i++) {
			if (visit[list[x][i]] == 0) {
				visit[list[x][i]] = 1;
				q.push(list[x][i]);
				cnt++;
			}
		}
	}
	if (res < cnt) {
		idx = 0;
		res = cnt;
		p[idx++] = t;
	}
	else if (res == cnt) {
		p[idx++] = t;
	}
}
int main()
{
	cin >> N >> M;
	int a, b;
	for (int i = 1; i <= M; i++) {
		cin >> a >> b;
		list[b].push_back(a);
	}
	for (int i = 1; i <= N; i++) 
		bfs(i);
	for (int i = 0; i < idx; i++) {
		cout << p[i] << " ";
	}
}