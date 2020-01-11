#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int C, N;
int dp[102];
const int M = 1000000007;

int tile(int n)
{
	if (n == 1) return 1;
	if (n == 2) return 2;
	int& res = dp[n];
	if (res != -1) return res;
	return res = (tile(n - 1) + tile(n - 2)) % M;
}

int main()
{
	cin >> C;
	while (C--) {
		cin >> N;
		memset(dp, -1, sizeof(dp));
		cout << tile(N) << endl;
	}
}