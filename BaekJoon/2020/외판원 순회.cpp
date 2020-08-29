#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int N;
int p[17][17];
int dp[17][1 << 17];

int dfs(int cur, int state) {
	if (state == (1 << N) - 1) {
		if (p[cur][0] != 0) return p[cur][0];
		else return 987654321;
	}

	if (dp[cur][state] != -1) // 방문한 지점이면 반환
		return dp[cur][state];

	int tmp = 987654321;
	for (int i = 0; i < N; i++) {
		if (state & (1 << i)) continue;
		if (p[cur][i]==0) continue;
		tmp = min(tmp, dfs(i, state | (1 << i)) + p[cur][i]);
	}

	return dp[cur][state] = tmp;
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> p[i][j];

	memset(dp, -1, sizeof(dp));

	cout << dfs(0, 1); //0번 노드에서 출발
}