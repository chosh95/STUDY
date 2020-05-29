#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int N, M;
vector<int> v[20001];
int visit[20001];
int maxidx, maxnum, maxcnt;

void bfs() {
	queue<int> q;
	q.push(1);
	visit[1] = 1;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int i = 0; i < v[x].size(); i++) {
			int nx = v[x][i];
			if (!visit[nx]) {
				visit[nx] = visit[x] + 1;
				q.push(nx);
			}
		}
	}
}

int main()
{
	cin >> N >> M;
	for (int a, b, i = 0; i < M; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	bfs();
	for (int i = 2; i <= N; i++) {
		if (visit[i] > maxnum) {
			maxnum = visit[i];
			maxidx = i;
			maxcnt = 1;
		}
		else if (visit[i] == maxnum) 
			maxcnt++;
		
	}
	cout << maxidx << " " << maxnum - 1 << " " << maxcnt;
}