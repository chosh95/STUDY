#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int dp[1002][1002];
string a, b;

int main()
{
	cin >> a >> b;
	int s1 = a.size();
	int s2 = b.size();
	for (int i = 0; i <= s1; i++) dp[i][0] = i;
	for (int j = 0; j <= s2; j++) dp[0][j] = j;

	for (int i = 1; i <= s1; i++) {
		for (int j = 1; j <= s2; j++) {
			if (a[i-1] == b[j-1]) dp[i][j] = dp[i - 1][j - 1];
			else {
				dp[i][j] = min(min(dp[i - 1][j], dp[i - 1][j - 1]), dp[i][j - 1]) + 1;
			}
		}
	}
	cout << dp[s1][s2];
}