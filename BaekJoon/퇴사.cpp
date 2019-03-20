#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int p[17][3] = { 0 };
	int dp[17] = { 0 };
	vector<vector<int>> v(17);
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> p[i][1] >> p[i][2];

	for (int i = 1; i <= N + 1; i++) {
		for (int j = p[i][1] + i; j <= N + 1; j++)
			v[j].push_back(i);
		while (!v[i].empty()) {
			int index = v[i].back();
			v[i].pop_back();
			if (p[index][2] + dp[index] > dp[i]) {
				dp[i] = p[index][2] + dp[index];
			}
		}

	}
	cout << dp[N + 1];
}