#include <iostream>
#include <algorithm>
using namespace std;
pair<int, int> p[501];
int dp[501];
int N,res;

int main()
{
	cin >> N;
	for (int i = 1; i <= N; i++) 
		cin >> p[i].first >> p[i].second;
	sort(p, p + N + 1);
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < i; j++) {
			if (p[j].second < p[i].second) {
				if (dp[j] >= dp[i]) {
					dp[i] = dp[j] + 1;
				}
			}
		}
		if (res < dp[i]) res = dp[i];
	}
	cout << N - res;
}