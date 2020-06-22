#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int N, K;
int p[201];
int dp[201][201];

int dfs(int start, int end) {
	if (start == end) return 0;
	int& res = dp[start][end];
	if (res != -1) return res;
	res = 987654321;

	for (int i = start; i < end; i++) {
		int tmp = p[start] != p[i+1] ? 1 : 0;
		res = min(res, dfs(start, i) + dfs(i + 1, end) + tmp);
	}
	return res;
}

int main()
{
	cin >> N >> K;
	for (int i = 1; i <= N; i++) cin >> p[i];
	memset(dp, -1, sizeof(dp));
	cout << dfs(1, N);
}