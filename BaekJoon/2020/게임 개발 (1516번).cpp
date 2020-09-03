#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

int N; 
int p[501]; // 각 건물 짓는 데 걸리는 시간
int indeg[501]; // 위상
vector<int> v[501]; // 각 건물과 연관된 건물
int dp[501];

void bfs()
{
	queue<int> q;
	for (int i = 1; i <= N; i++)
		if (indeg[i] == 0) {
			dp[i] = p[i];
			q.push(i); //바로 지을 수 있는 건물 짓기
		}
	
	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int i = 0; i < v[cur].size(); i++) {
			int next = v[cur][i];
			indeg[next]--;
			if (indeg[next] == 0) {
				int maxTime = 0;
				for (int i = 0; i < v[next].size(); i++)
					maxTime = max(maxTime, dp[v[next][i]]);
				dp[next] = maxTime + p[next];
				q.push(next);
			}
		}
	}
}

int main()
{
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> p[i];
		int tmp;
		while (true) {
			cin >> tmp;
			if (tmp == -1) break;
			v[i].push_back(tmp);
			v[tmp].push_back(i);
			indeg[i]++;
		}
	}

	bfs();

	for (int i = 1; i <= N; i++)
		cout << dp[i] << "\n";
}