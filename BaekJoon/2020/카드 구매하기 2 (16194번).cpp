#include <iostream>
#include <algorithm>
using namespace std;
int p[1001];
int dp[1001];
int N;

//현재 카드 몇 개인지, top-down
int dfs(int cnt) {
	if (cnt <= 0) return 0;
	if (dp[cnt] != 987654321) return dp[cnt];

	for (int i = 1; i <= N; i++) {
		if(cnt-i >= 0)
			dp[cnt] = min(dp[cnt], dfs(cnt - i) + p[i]);
	}

	return dp[cnt];
}

//현재 카드 몇 개인지, bottom-up
int dfs2(int cnt) {
	if (cnt >= N) return 0;
	if (dp[cnt] != 987654321) return dp[cnt];

	for (int i = 1; i <= N; i++) {
		if (cnt + i <= N)
			dp[cnt] = min(dp[cnt], dfs2(cnt + i) + p[i]);
	}

	return dp[cnt];
}

//현재 몇번째 카드를 조사중인지, 현재 카드 몇개 모았는지
int dfs3(int idx, int cnt) {
	if (cnt >= N) return 0;
	if (dp[cnt] != 987654321) return dp[cnt];

	for (int i = idx; i <= N; i++) {
		if (cnt + i <= N)
			dp[cnt] = min(dp[cnt], dfs3(i, cnt + i) + p[i]);
	}
	return dp[cnt];
}

int main()
{
	cin >> N;

	dp[0] = 987654321;
	for (int i = 1; i <= N; i++) {
		cin >> p[i];
		dp[i] = 987654321;
	}
	
	//cout << dfs(N); // top-down
	//cout<< dfs2(0); //bottom-up
	cout << dfs3(1, 0);
	
}