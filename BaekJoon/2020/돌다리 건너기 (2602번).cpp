#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int dp[21][2][101]; // (입력 문자열)(악마/천사)(다리 인덱스)
char p[2][101]; // (악마/천사)(다리)
char origin[21]; // 입력 문자열

int originLen, bridgeLen;

int main()
{
	string tmp;
	cin >> tmp;
	originLen = tmp.size();
	for (int i = 1; i <= tmp.size(); i++)
		origin[i] = tmp[i - 1];

	cin >> tmp;
	bridgeLen = tmp.size();
	for (int i = 1; i <= tmp.size(); i++)
		p[0][i] = tmp[i - 1];
	
	cin >> tmp;
	for (int i = 1; i <= tmp.size(); i++)
		p[1][i] = tmp[i - 1];


	for (int j = 0; j <= 1; j++) {
		for (int k = 1; k <= bridgeLen; k++) {
			if (p[j][k] == origin[1]) {
				dp[1][j][k] = 1;
			}
		}
	}

	for (int i = 2; i <= originLen; i++) {
		for (int j = 0; j <= 1; j++) {
			for (int k = 1; k <= bridgeLen; k++) {
				if (p[j][k] == origin[i]) {
					int cnt = 0;
					for (int m = 1; m < k; m++) {
						cnt += dp[i - 1][1 - j][m];
					}
					dp[i][j][k] = cnt;
				}
			}
		}
	}

	int res = 0;
	for (int i = 0; i <= 1; i++) {
		for (int j = 1; j <= bridgeLen; j++) {
			res += dp[originLen][i][j];
		}
	}
	cout << res;
}