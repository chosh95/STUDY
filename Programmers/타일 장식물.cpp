#include <iostream>
#include <string>
#include <vector>

using namespace std;
long long dp[81];

long long solution(int N) {
	long long answer = 0;
	dp[0] = dp[1] = dp[2] = 1;
	for (int i = 3; i <= N+1; i++)
		dp[i] = dp[i - 1] + dp[i - 2];
	answer = 2 * (dp[N] + dp[N + 1]);
	return answer;
}

int main()
{
	cout << solution(80);
}