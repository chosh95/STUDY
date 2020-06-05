#include <iostream>
#include <algorithm>
using namespace std;
int T, K;
pair<int,int> p[101]; // p[i] = <금액, 개수>
int dp[101][10001]; // i번째 동전까지 사용해서 cost를 만드는 경우의 수

int main()
{
	cin >> T;
	cin >> K;
	for (int a, b, i = 1; i <= K; i++) {
		cin >> a >> b;
		p[i] = { a,b };
	}
	sort(p+1, p + K+1);
	dp[0][0] = 1;
	for (int i = 1; i <= K; i++) {
		for (int j= 0; j <= p[i].second; j++) {
			for (int k = 0; k <= T; k++) {
				if (p[i].first * j + k > T) break;
				dp[i][k + p[i].first *j] += dp[i-1][k];
			}
		}
	}

	cout << dp[K][T];
}