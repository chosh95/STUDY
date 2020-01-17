#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int C, N, M;
int price[21], need[21];
int dp[201];
int sushi()
{
	int res = 0;
	dp[0] = 0;
	for (int budget = 1; budget <= M; budget++) {
		int cand = 0;
		for (int j = 0; j < N; j++) 
			if (price[j] <= budget) 
				cand = max(cand, dp[(budget - price[j]) % 201] + need[j]);
		dp[budget % 201] = cand;
		res = max(res, cand);
	}
	return res;
}
int main()
{
	cin >> C;
	while (C--) {
		cin >> N >> M;
		for (int i = 0; i < N; i++) {
			cin >> price[i] >> need[i];
			price[i] /= 100;
		}
		M /= 100;
		cout << sushi() << endl;
	}
}