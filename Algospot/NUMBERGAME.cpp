#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int C, N;
int p[51];
int dp[51][51];
const int EMPTY = -987654321;

int play(int left, int right)
{
	if (left > right) return 0;
	int& res = dp[left][right];
	if (res != EMPTY) return res;

	res = max(p[left] - play(left + 1, right), p[right] - play(left, right - 1));
	if (right - left + 1 >= 2) {
		res = max(res, -play(left + 2, right));
		res = max(res, -play(left, right - 2));
	}
	return res;
}

int main()
{
	cin >> C;
	while (C--) {
		cin >> N;
		for (int i = 0; i < 51; i++)
			for (int j = 0; j < 51; j++) 
				dp[i][j] = EMPTY;
			
		
		for (int i = 0; i < N; i++) cin >> p[i];
		cout << play(0, N - 1) << endl;
	}
}