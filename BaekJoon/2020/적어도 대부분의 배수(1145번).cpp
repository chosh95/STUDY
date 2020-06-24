#include <iostream>
#include <algorithm>
using namespace std;
int p[6];
int visit[6];
int res = 987654321;

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

int lcm(int a, int b) {
	int cd = gcd(a, b);
	return a * b / cd;
}

void dfs(int idx, int cnt, int cur) {


	if (cnt == 3) {
		res = min(res, cur);
		return;
	}
	if (idx > 5) return;

	dfs(idx + 1, cnt, cur);

	dfs(idx + 1, cnt + 1, lcm(cur, p[idx]));

	return;
}

int main()
{
	for (int i = 1; i <= 5; i++)
		cin >> p[i];
	dfs(1, 0, 1);
	cout << res;
}