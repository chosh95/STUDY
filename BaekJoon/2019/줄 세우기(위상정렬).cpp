#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N, M;
int indegree[32000 + 1];	//indegree[x] = 0 이면 우선순위가 높으므로 먼저 출력
vector<int> v[32001];
void bfs()
{
	queue<int> q;
	for (int i = 1; i <= N; i++){
		if (indegree[i] == 0) q.push(i);
	}
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		cout << cur << " ";
		for (int i = 0; i < v[cur].size(); i++) {
			indegree[v[cur][i]]--;
			if (indegree[v[cur][i]] == 0) q.push(v[cur][i]);
		}
	}
}

int main()
{
	cin >> N >> M;
	int a, b;
	for (int i = 0; i < M; i++) {
		scanf("%d%d", &a, &b);
		v[a].push_back(b);
		indegree[b]++;
	}
	bfs();
	return 0;
}