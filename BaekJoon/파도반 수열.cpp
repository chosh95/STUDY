<<<<<<< HEAD
#include <iostream>
using namespace std;
long long dp[105];
int main()
{
	int T;
	cin >> T;
	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 1;
	for (int i = 4; i <= 100; i++) dp[i] = dp[i - 2] + dp[i - 3];
	for (int i = 1; i <= T; i++) {
		int N;
		cin >> N;
		cout << dp[N] << endl;
	}
=======
#include <iostream>
using namespace std;
long long dp[105];
int main()
{
	int T;
	cin >> T;
	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 1;
	for (int i = 4; i <= 100; i++) dp[i] = dp[i - 2] + dp[i - 3];
	for (int i = 1; i <= T; i++) {
		int N;
		cin >> N;
		cout << dp[N] << endl;
	}
>>>>>>> 7f36c76f4ad21fe245254ea3f1b3c6e1e3bbbd90
}