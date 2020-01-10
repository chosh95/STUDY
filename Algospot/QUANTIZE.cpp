#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
int C, N, S;
int sum[101], sqSum[101];
int dp[101][11];

int score(int start, int end)
{
	int tmpSum = sum[end] - (start == 0 ? 0 : sum[start-1]);
	int tmpSq = sqSum[end] - (start == 0 ? 0 : sqSum[start-1]);
	int m = int(0.5 + (double)tmpSum / (end - start + 1));
	int res = tmpSq - 2 * m * tmpSum + m * m * (end - start + 1);
	return res;
}
int quan(int start, int part)
{
	if (start == N) return 0;
	if (part == 0) return 987654321;
	int& res = dp[start][part];
	if (res != -1) return res;
	res = 987654321;
	for (int i = 1; i + start <= N; i++) {
		res = min(res, quan(start + i, part - 1) + score(start,start+i-1));
	}
	return res;
}

int main()
{
	cin >> C;
	while (C--) {
		cin >> N >> S;
		//초기화
		vector<int> v(N);
		memset(dp, -1, sizeof(dp));
		memset(sum, 0, sizeof(sum));
		memset(sqSum, 0, sizeof(sqSum));
		//입력부
		for (int i = 0; i < N; i++) {
			cin >> v[i];
		}
		//사전 계산
		sort(v.begin(), v.end());
		sum[0] = v[0];
		sqSum[0] = v[0] * v[0];
		for (int i = 1; i < N; i++) {
			sum[i] = (sum[i - 1] + v[i]);
			sqSum[i] = sqSum[i - 1] + (v[i] * v[i]);
		}
		//결과출력
		cout << quan(0, S) << endl;
	}
}