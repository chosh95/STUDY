#include <iostream>
using namespace std;

long long dp[100];
int main()
{
	int T,n;;
	cin >> T;
	dp[0] = dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	for (int i = 4; i <= 67; i++) 
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3] + dp[i - 4];
	
	while (T--) {
		cin >> n;
		cout << dp[n] << "\n";
	}
	return 0;
}