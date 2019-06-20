#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
vector<int> v[100001];
int parent[100001];
void bfs()
{
	parent[1] = 1;
	queue<int> q;
	q.push(1);
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int i = 0; i < v[x].size(); i++) {
			if (!parent[v[x][i]]) {
				parent[v[x][i]] = x;
				q.push(v[x][i]);
			}
		}
	}
}

int main()
{
	int N, a, b;
	cin >> N;
	for (int i = 1; i < N; i++) {
		scanf("%d%d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	bfs();
	for (int i = 2; i <= N; i++) 
		cout << parent[i] << "\n";
	
}