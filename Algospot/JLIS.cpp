#include <iostream>
#include <algorithm>
#include <memory.h>
using namespace std;
const long long NEGINF = numeric_limits<long long>::min();
int C, N, M;
int A[102], B[102];
int dp[102][102];

int jlis(int a, int b) //AÀÇ index, BÀÇ index
{
	int& ret = dp[a + 1][b + 1];
	if (ret != -1) return ret;
	ret = 0;
	long long aa = (a == -1 ? NEGINF : A[a]);
	long long bb = (b == -1 ? NEGINF : B[b]);
	long long maxElement = max(aa, bb);

	for (int na = a + 1; na < N; na++) {
		if (maxElement < A[na]) {
			ret = max(ret, jlis(na, b) + 1);
		}
	}
	for (int nb = b + 1; nb < M; nb++) {
		if (maxElement < B[nb]) {
			ret = max(ret, jlis(a, nb) + 1);
		}
	}
	return ret;
}

int main()
{
	cin >> C;
	while (C--) {
		memset(dp, -1, sizeof(dp));
		cin >> N >> M;
		for (int i = 0; i < N; i++) cin >> A[i];
		for (int j = 0; j < M; j++) cin >> B[j];
		cout << jlis(-1, -1) << endl;
	}
}