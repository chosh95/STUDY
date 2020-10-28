#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N;
long long dp[31][31];

long long dfs(int w, int h) {
	if (w == 0 && h == 0) return 1;
	if (dp[w][h] != 0) return dp[w][h];

	if (w != 0)
		dp[w][h] += dfs(w - 1, h + 1);
	if (h != 0)
		dp[w][h] += dfs(w, h - 1);

	return dp[w][h];
}

int main()
{
	while (true) {
		cin >> N;
		if (N == 0) break;
		cout << dfs(N, 0) << "\n";
	}
}