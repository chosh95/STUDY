#include <iostream>
using namespace std;
int N, M;
int dp[41];

int main()
{
	cin >> N >> M;
	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= 40; i++)
		dp[i] = dp[i - 1] + dp[i - 2];
	
	int res = 1;
	int tmp = 0;
	int k;
	for (int i = 0; i < M; i++) {
		cin >> k;
		res *= dp[k - tmp-1];
		tmp = k;
	}
	res *= dp[N - tmp];
	cout << res;
}