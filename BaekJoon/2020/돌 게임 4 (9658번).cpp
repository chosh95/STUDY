#include <iostream>
#include <algorithm>
using namespace std;
int N;
int dp[1001];


int main()
{
	cin >> N;
	dp[1] = 0; // 짐
	dp[2] = 1; // 이김
	dp[3] = 0;
	dp[4] = 1;
	for (int i = 5; i <= N; i++) {
		if (dp[i - 1] == 0 || dp[i - 3] == 0 || dp[i - 4] == 0)
			dp[i] = 1;
		else
			dp[i] = 0;
	}
	if (dp[N] == 0)
		cout << "CY";
	else
		cout << "SK";
}
