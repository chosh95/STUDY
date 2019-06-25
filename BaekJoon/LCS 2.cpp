#include <iostream>
#include <string>
using namespace std;
int dp[1002][1002];
char ans[1002];

int main()
{
	string s1, s2;
	cin >> s1 >> s2;
	int res = 0;
	for (int i = 1; i <= s1.size(); i++) {
		for (int j = 1; j <= s2.size(); j++) {
			if (s1[i-1] == s2[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
			else {
				if (dp[i][j-1] > dp[i-1][j]) dp[i][j] = dp[i][j-1];
				else dp[i][j] = dp[i-1][j];
			}
			if (dp[i][j] > res) res = dp[i][j];
		}
	}
	cout << res << endl;
	string str;
	int x = s1.size(), y = s2.size();
	while (x>=0 && y>=0) {
		if (dp[x][y] == dp[x][y - 1]) y--;
		else if (dp[x][y] == dp[x-1][y]) x--;
		else {
			str = s1[x-1] + str;
			x--; y--;
		}
	}
	cout << str;
}