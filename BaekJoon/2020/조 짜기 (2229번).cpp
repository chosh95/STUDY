#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int N;
int p[1001];
int dp[1001][1001];

int dfs(int start, int end) {
	if (start == end) return 0;
	int& res = dp[start][end];
	if (res != -1) return res;
	res = p[start]-p[end];
	if (res < 0) res *= -1;
	for (int i = start; i < end; i++) {
		res = max(res, dfs(start, i) + dfs(i + 1, end));
	}
	return res;
}

int main()
{
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> p[i];
	memset(dp, -1, sizeof(dp));
	cout << dfs(1, N);
}