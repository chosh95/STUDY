#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
vector<int> tree[51];
int visit[51];
int N, root, res;
int deleteNode;

void bfs()
{
	memset(visit, 0, sizeof(visit));
	queue<int> q;
	if (root == deleteNode) return;
	q.push(root);
	visit[root] = 1;

	while (!q.empty()) {
		int x = q.front();
		q.pop();

		for (int i = 0; i < tree[x].size(); i++) {
			int nx = tree[x][i];
			if (nx == deleteNode || visit[nx] != 0) continue;
			q.push(nx);
			visit[x]++;
			visit[nx] = 1;
		}
	}
}

int main()
{
	cin >> N;
	for (int tmp, i = 0; i < N; i++) {
		cin >> tmp;
		if (tmp == -1) root = i;
		else tree[tmp].push_back(i);
	}
	
	cin >> deleteNode;
	bfs();

	res = 0;
	for (int i = 0; i < N; i++) 
		if (visit[i] == 1)
			res++;
	
	cout << res;
}