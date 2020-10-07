#include <iostream>
#include <algorithm>
using namespace std;

int N;
int p[5001];
int dp[5001][5001];

int dfs(int start, int end) {
	if (start >= end) return 0;

	if (dp[start][end] != 0) return dp[start][end];

	int cur = 987654321;
	if (p[start] == p[end])
		cur = min(cur, dfs(start + 1, end - 1));
	else {
		cur = min(dfs(start,end-1) + 1, dfs(start + 1, end) + 1);
	}
		
	return dp[start][end] = cur;
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> p[i];

	cout << dfs(0, N - 1);
}