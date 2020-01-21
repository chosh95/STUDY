#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int N, M;
string dp[101][101];

string addbig(string num1, string num2)
{
	long long sum = 0;
	string ret;
	while (!num1.empty() || !num2.empty() || sum) {
		if (!num1.empty()) {
			sum += num1.back() - '0';
			num1.pop_back();
		}
		if (!num2.empty()) {
			sum += num2.back() - '0';
			num2.pop_back();
		}
		ret.push_back((sum % 10) + '0');
		sum /= 10;
	}
	reverse(ret.begin(), ret.end());
	return ret;
}

string comb(int n, int m)
{
	if (n == m || m == 0) return "1";
	string &ret = dp[n][m];
	if (ret != "") return ret;
	ret = addbig(comb(n - 1, m - 1), comb(n - 1, m));
	return ret;
}
int main()
{
	cin >> N >> M;
	cout << comb(N,M);
}