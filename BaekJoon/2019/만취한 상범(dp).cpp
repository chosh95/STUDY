#include <iostream>
using namespace std;
int dp[105][105]; //dp[i][j]에서 i는 round j는 방의 상태(0이면 닫힘 1이면 열림)
int main()
{
	int T;
	cin >> T;
	for (int i = 1; i <= 100; i++) dp[1][i] = 1;
	for (int i = 2; i <= 100; i++) {
		for (int j = 1; j <= 100; j++) {
			if (j%i == 0) {
				if (dp[i - 1][j] == 0) dp[i][j] = 1;
				else dp[i][j] = 0;
			}
			else dp[i][j] = dp[i - 1][j];
		}
	}
	while (T--) {
		int N,res=0;
		cin >> N;
		for (int i = 1; i <= N; i++) {
			if (dp[N][i]==1) res++;
		}
		cout << res << endl;
	}
}