#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
using namespace std;

int p[2001];
bool dp[2001][2001];

int main()
{
	int N, M;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		scanf("%d", &p[i]);
		dp[i][i] = true;
	}
	for (int i = 1; i <= N - 1; i++) {
		if (p[i] == p[i + 1]) dp[i][i + 1] = true;
		else false;
	}
	for (int i = 2; i <= N - 1; i++) {
		for (int j = 1; j + i <= N; j++) {
			if (p[j] == p[j + i] && dp[j + 1][j + i - 1] == true) {
				dp[j][j + i] = true;
			}
		}
	}
	cin >> M;
	int a, b;
	while (M--) {
		scanf("%d%d", &a, &b);
		if (dp[a][b] == true) cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}
