#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N;
vector<int> v[1000001];
vector<int> child[1000001];
int visit[1000001];
int dp[1000001][2]; // dp[i][0] : i가 얼리어답터일 때, dp[i][1] : 얼리어답터 아닐 때

void makeChild(int cur) {
	for (auto next : v[cur]) {
		if (visit[next] == 0) {
			visit[next] = 1;
			child[cur].push_back(next);
			makeChild(next);
		}
	}
}

int dfs(int cur, int state) {
	
	if (dp[cur][state] != 0) return dp[cur][state];

	if (state == 0) {
		for (int next : child[cur]) {
			dp[cur][state] += dfs(next, 1);
		}
	}
	else {
		for (int next : child[cur]) {
			dp[cur][state] += min(dfs(next,0), dfs(next, 1));
		}
		dp[cur][state]++;
	}

	return dp[cur][state];
}

int main()
{
	cin >> N;
	for (int u, w, i = 1; i < N; i++) {
		cin >> u >> w;
		v[u].push_back(w);
		v[w].push_back(u);
	}

	visit[1] = 1;
	makeChild(1);

	cout << min(dfs(1, 0), dfs(1, 1));
}