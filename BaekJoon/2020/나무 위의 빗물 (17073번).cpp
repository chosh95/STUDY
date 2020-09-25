#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int N;
double W;
vector<int> v[500001];
int visit[500001];
double result;

void bfs() {
	queue<pair<int, double>> q;
	q.push({ 1,W });
	visit[1] = true;

	double res = 0;
	int cnt = 0;
	while (!q.empty()) {
		int cur = q.front().first;
		double water = q.front().second;
		q.pop();

		int nextSize = 0;
		for (int i = 0; i < v[cur].size(); i++)
			if (visit[v[cur][i]] == 0) nextSize++;
		
		if (nextSize == 0) {
			res += water;
			cnt++;
			continue;
		}

		for (int i = 0; i < v[cur].size(); i++) {
			int next = v[cur][i];
			if (visit[next] == 1) continue;
			visit[next] = 1;
			q.push({ next,water / nextSize });
		}
	}

	result = res / cnt;
}

int main()
{
	cin >> N >> W;
	for (int a, b, i = 0; i < N-1; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	bfs();
	cout << fixed;
	cout.precision(10);
	cout << result;
}