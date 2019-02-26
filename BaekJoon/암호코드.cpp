#include <iostream>
#include <string>
using namespace std;
int p[5001];
long long dp[5001]; //d[i] = i개의 숫자로 만들 수 있는 암호 수

int main()
{
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++) 
		p[i + 1] = s[i] - '0';
	
	dp[0] = dp[1] = 1;
	for (int i = 2; i <= s.size(); i++) {
		if (p[i] != 0) dp[i] = dp[i - 1] % 1000000;
		int tmp = p[i - 1] * 10 + p[i];
		if (10 <= tmp && tmp <= 26) dp[i] += dp[i - 2] % 1000000;
	}
	if (p[1] == 0) cout << 0;
	else cout << dp[s.size()]% 1000000;
}