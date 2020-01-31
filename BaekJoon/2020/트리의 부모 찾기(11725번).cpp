#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
int N;
vector<int> v[100001];
int p[100001];

void bfs()
{
	queue<int> q;
	memset(p, -1, sizeof(p));
	q.push(1);
	p[1] = 1;
	while (!q.empty()) {
		int here = q.front();
		q.pop();
		for (int i = 0; i < v[here].size(); i++) {
			int next = v[here][i];
			if (p[next] == -1) {
				q.push(next);
				p[next] = here;
			}
		}
	}
}

int main()
{
	cin >> N;
	for (int a, b, i = 0; i < N-1; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	bfs();
	for (int i = 2; i <= N; i++)
		cout << p[i] << "\n";
}