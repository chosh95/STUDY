#include <iostream>
#include <cstring>
using namespace std;
int C, N;
int dp[101][101];
const int MOD = 10000000;
//n개의 정사각형 중 맨 위 가로줄에 first개의 정사각형을 갖는 폴리오미노 수 반환
int poly(int n, int first) 
{
	if (n == first) {
		return 1;
	}
	int& res = dp[n][first];
	if (res != -1) return res;
	res = 0;
	for (int second = 1; second <= n - first; second++) {
		if(first==0) res += (poly(n - first, second)) % MOD;
		else res += (poly(n - first, second) * (first + second - 1))%MOD;
		res %= MOD;
	}
	return res;
}


int main()
{
	cin >> C;
	while (C--) {
		memset(dp, -1, sizeof(dp));
		cin >> N;
		int sum = 0;
		/* 기존 코드에서 정답을 위한 방법
		for (int i = 1; i <= N; i++) {
			sum += poly(N, i);
			sum %= MOD;
		}
		cout << sum << endl; */
		//수정한 방법
		cout << poly(N, 0) << endl;
	}
}