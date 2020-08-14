#include <iostream>
#include <algorithm>
using namespace std;
int A, B, C, N;
int dp[301][301][301];

bool isPossible() {
	for (int i = 0; i < 301; i++) {
		dp[i][0][0] = i * A;
		if (dp[i][0][0] > N) break;

		for (int j = 0; j < 301; j++) {
			if (j != 0) dp[i][j][0] = dp[i][j - 1][0] + B;
			if (dp[i][j][0] > N) break;

			for (int k = 0; k < 301; k++) {
				if (k != 0) dp[i][j][k] = dp[i][j][k - 1] + C;
				if (dp[i][j][k] == N) return true;
				else if (dp[i][j][k] > N) break;
			}
		}
	}
	return false;

	/* 
	for (int i = 0; i < 301; i++) {
		for (int j = 0; j < 301; j++) {
			for (int k = 0; k < 301; k++) {
				int num = i * A + j * B + k * C;
				if (num == N) return true;
				else if (num > N) break;
			}
		}
	}
	return false;
	*/
}

int main()
{
	cin >> A >> B >> C >> N;
	if (isPossible())
		cout << 1;
	else
		cout << 0;

}