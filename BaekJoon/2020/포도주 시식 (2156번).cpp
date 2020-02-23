#include <iostream>
#include <algorithm>
using namespace std;
int N;
int p[10001];
int dp[10001];

int main()
{
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> p[i];
	dp[1] = p[1];
	dp[2] = dp[1] + p[2];
	for (int i = 3; i <= N; i++) {
		dp[i] = max(dp[i - 2] + p[i], dp[i - 3] + p[i-1] + p[i]); //i번째를 첫번째로 마시는 경우, 두번 연속 마신경우
		dp[i] = max(dp[i], dp[i - 1]); // 안 마시고 넘기는 경우
	}

	cout << dp[N];
}