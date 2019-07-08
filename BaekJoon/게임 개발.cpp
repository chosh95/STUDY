#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
int indegree[501]; //����
vector<int> v[501];	//����� �ǹ� ����Ʈ
int p[501], res[501]; //�ǹ� ���� �ð�, ���
int N;
void bfs()
{
	queue<int> q;
	for (int i = 1; i <= N; i++) 
		if (indegree[i] == 0) {
			q.push(i);
			res[i] = p[i];
		}

	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int i = 0; i < v[x].size(); i++) {
			int nx = v[x][i];
			res[nx] = max(res[nx], res[x] + p[nx]);
			if (--indegree[nx] == 0){
				q.push(nx);
			}
		}
	}
}

int main()
{
	cin >> N;
	for (int i = 1,a; i <= N; i++) {
		cin >> p[i];
		while (true) {
			cin >> a;
			if (a == -1) break;
			v[a].push_back(i);
			indegree[i]++;
		}
	}
	bfs();
	for (int i = 1; i <= N; i++) cout << res[i] << "\n";
	return 0;
}