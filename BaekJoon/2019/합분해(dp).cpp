#include <iostream>
using namespace std;
long long dp[201][201]; // dp[n][k]는 n을 k개 이용해 만드는 방법의 수

int main()
{
	int N, K;
	cin >> N >> K;
	for (int i = 1; i <= N; i++) 
		dp[i][1] = 1;
	for (int i = 1; i <= K; i++)
		dp[1][i] = i;
	
	for (int i = 2; i <= N; i++) {
		for (int j = 2; j <= K; j++)
			dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % 1000000000;
	}
	cout << dp[N][K] % 1000000000;
}