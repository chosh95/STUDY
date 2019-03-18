#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <memory.h>
#include <queue>
using namespace std;
int V, E;
int p[20001];
vector<int> v[20001];
bool res = true;
void bfs(int i)
{
	queue<int> q;
	q.push(i);
	p[i] = 1;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int i = 0; i < v[x].size(); i++) {
			int nx = v[x][i];
			if (p[nx] == 0) {
				p[nx] = 3 - p[x];
				q.push(nx);
			}
			else if (p[nx] == p[x] && p[nx] != 0) {
				res = false;
				break;
			}
		}
	}
}

int main()
{
	int K;
	cin >> K;
	while (K--) {
		cin >> V >> E;
		int a, b;
		res = true;
		memset(p, 0, sizeof(p));
		memset(v, 0, sizeof(v));

		for (int i = 1; i <= E; i++) {
			scanf("%d%d", &a, &b);
			v[a].push_back(b);
			v[b].push_back(a);
		}
		for (int i = 1; i <= V; i++) {
			if (p[i] == 0) bfs(i);
			if (!res) break;
		}
		if (res) cout << "YES\n";
		else cout << "NO\n";
	}
}