#include <iostream>
using namespace std;
int a, b, c;
int dp[51][51][51];

int w(int a, int b, int c)
{
	int res = 0;
	if (a <= 0 || b <= 0 || c <= 0) return 1;
	if (dp[a][b][c] != 0) return dp[a][b][c];
	else if (a > 20 || b > 20 || c > 20) res = w(20, 20, 20);
	else if (a < b && b < c) res = w(a, b, c - 1), +w(a, b - 1, c - 1) - w(a, b - 1, c);
	else res = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
	dp[a][b][c] = res;
	return res;
}

int main()
{
	while (true) {
		cin >> a >> b >> c;
		if (a == -1 && b == -1 && c == -1) break;
		printf("w(%d, %d, %d) = %d\n", a, b, c, w(a, b, c));
	}
}