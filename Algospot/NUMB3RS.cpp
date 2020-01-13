#include <iostream>
#include <cstring>
using namespace std;
int A[51][51];
int link[51];
double dp[51][101];
int C, N, d, p, t, q;

//day일째에 village마을에서 도망치는 확률
double cal(int village, int day)
{
	if (day == 0) return (village == p ? 1.0 : 0.0);
	double& res = dp[village][day];
	if (res != -1.0) return res;
	res = 0.0;
	for (int i = 0; i < N; i++) {
		if (A[village][i]) {
			res += cal(i,day-1) / link[i];
		}
	}
	return res;
}


int main()
{
	cin >> C;
	while (C--) {
		cin >> N >> d >> p;
		memset(A, 0, sizeof(A));
		memset(link, 0, sizeof(link));
		for (int i = 0; i < N; i++) {
			for (int j = 0; j <= d; j++) {
				dp[i][j] = -1.0;
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> A[i][j];
				if (A[i][j] == 1) {
					link[i]++;
				}
			}
		}
		cin >> t;
		while (t--) {
			cin >> q;
			cout.precision(8);
			cout << cal(q,d) << " ";
		}
		cout << endl;
	}
}