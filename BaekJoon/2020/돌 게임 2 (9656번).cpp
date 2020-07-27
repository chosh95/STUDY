#include <iostream>
#include <algorithm>
using namespace std;
int N;
int dp[1001];

void dfs(int turn, int cnt) {
	if (dp[cnt] != 0) return;
	dfs(turn * -1, cnt - 1);
	dfs(turn * -1, cnt - 3);

	if (dp[cnt - 1] == turn && dp[cnt - 3] == turn)
		dp[cnt] = turn * -1;
	else
		dp[cnt] = turn;
}

int main()
{
	cin >> N;
	dp[1] = -1;
	dp[2] = 1;
	dp[3] = -1;

	dfs(1, N);
	if (dp[N] == 1)
		cout << "SK";
	else
		cout << "CY";
}