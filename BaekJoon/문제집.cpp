#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int indegree[32001];
vector<int> v[32001];
int N, M;
void bfs()
{
	priority_queue<int> pq;
	for (int i = 1; i <= N; i++) 
		if (indegree[i] == 0) pq.push(-i);
	while (!pq.empty()) {
		int x = -pq.top();
		cout << x << " ";
		pq.pop();
		for (int i = 0; i < v[x].size(); i++) {
			int nx = v[x][i];
			indegree[nx]--;
			if (indegree[nx] == 0) pq.push(-nx);
		}
	}
}

int main()
{
	cin >> N >> M;
	int a, b;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		indegree[b]++;
	}
	bfs();
}