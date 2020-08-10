#include <string>
#include <vector>
#include <iostream>
using namespace std;
long long dp[5001];

int solution(int n) {
	if (n % 2 == 1) return 0;
	dp[0] = 1;
	dp[2] = 3;

	for (int i = 4; i <= n; i+=2) {
		dp[i] = dp[i - 2] * 3 + 2;
		for (int j = i-4; j >=2; j-=2) {
			dp[i] += dp[j] * 2;
		}
		dp[i] %= 1000000007;
	}
	return dp[n];
}

int main()
{
	cout << solution(18);
}