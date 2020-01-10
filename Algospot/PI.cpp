#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int C, len;
string str;
int dp[10003];
int score(int start, int end)
{
	bool tmp = true;
	for (int i = start+1; i <= end; i++) {
		if (str[i] != str[i - 1]) {
			tmp = false;
			break;
		}
	}
	if (tmp) return 1;

	tmp = true;
	for (int i = start + 1; i <= end; i++) {
		if (str[i] - 1 != str[i - 1]) {
			tmp = false;
			break;
		}
	}
	if (tmp) return 2;
	tmp = true;
	for (int i = start + 1; i <= end; i++) {
		if (str[i] + 1 != str[i - 1]) {
			tmp = false;
			break;
		}
	}
	if (tmp) return 2;

	tmp = true;
	for (int i = start + 2; i <= end; i++) {
		if (str[i] != str[i - 2]) {
			tmp = false;
			break;
		}
	}
	if (tmp) return 4;

	tmp = true;
	for (int i = start + 1; i <= end; i++) {
		if (str[i] - str[i - 1] != str[start + 1] - str[start]) {
			tmp = false;
			break;
		}
	}
	if (tmp) return 5;
	return 10;
}
int pi(int start)
{
	if (start == len) return 0;
	int& res = dp[start];
	if (res != -1) return res;
	res = 987654321;
	for (int i = 3; i < 6; i++) {
		if (start + i <= len) {
			res = min(res, pi(start + i) + score(start, start + i - 1));
		}
	}
	return res;
}

int main()
{
	cin >> C;
	while (C--) {
		cin >> str;
		len = str.size();
		memset(dp, -1, sizeof(dp));
		cout << pi(0) << endl;
	}
}