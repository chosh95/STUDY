#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <memory.h>
using namespace std;

int N, M, K, X;
vector<int> v[300001];
int visit[300010];
vector<int> res;

void dijk() {
	fill(&visit[0], &visit[300000], 300000);
	priority_queue<int> q;
	q.push(X);
	visit[X] = 0;

	while (!q.empty()) {
		int cur = q.top();
		q.pop();

		for (int nx : v[cur]) {
			if (visit[nx] > visit[cur] + 1) {
				visit[nx] = visit[cur] + 1;
				q.push(nx);
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M >> K >> X;
	for (int a, b, i = 0; i < M; i++) {
		cin >> a >> b;
		v[a].push_back(b);
	}

	dijk();

	for (int i = 1; i <= N; i++)
		if (visit[i] == K) 
			res.push_back(i);
	
	sort(res.begin(), res.end());

	if (res.empty()) cout << "-1";
	else {
		for (int x : res) {
			cout << x << "\n";
		}
	}
}
