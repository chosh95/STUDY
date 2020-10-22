#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>
using namespace std;
int N;
int p[10001];
vector<int> v[10001];
vector<int> child[10001];
int visit[10001];
int dp[10001][2];

void makeTree(int cur) {
	visit[cur] = 1;

	for (int next : v[cur]) {
		if (!visit[next]) {
			child[cur].push_back(next);
			makeTree(next);
		}
	}
}

int dfs(int cur, int state) {
	if (dp[cur][state] != 0)
		return dp[cur][state];

	if (state == 0) {
		for (int next : child[cur]) {
			dp[cur][state] += max(dfs(next,0),dfs(next, 1));
		}
	}
	else {
		for (int next : child[cur]) {
			dp[cur][state] += dfs(next, 0);
		}
		dp[cur][state] += p[cur];
	}

	return dp[cur][state];
}

int main()
{
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> p[i];
	for (int a, b, i = 1; i < N; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	makeTree(1);

	cout << max(dfs(1, 0), dfs(1, 1));
}