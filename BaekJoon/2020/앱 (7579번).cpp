#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int memory[101];
int cost[101];
int dp[101][10001]; // i번 앱부터 조사해서 j비용으로 확보한 메모리 크기
int N, M;

int dfs(int idx, int curCost) {
	if (idx > N) return 0;

	int& res = dp[idx][curCost];
	if (res != -1) return res;

	res = dfs(idx + 1, curCost);
	if (cost[idx] <= curCost)
		res = max(res, dfs(idx + 1, curCost - cost[idx]) + memory[idx]);

	return res;
}

int main()
{
	cin >> N >> M;
	for (int i = 1; i <= N; i++) cin >> memory[i];
	for (int i = 1; i <= N; i++) cin >> cost[i];
	memset(dp, -1, sizeof(dp));

	for (int i = 0; i <= 10000; i++) {
		int res = dfs(1, i);
		if (res >= M) {
			cout << i;
			break;
		}
	}
	return 0;
}