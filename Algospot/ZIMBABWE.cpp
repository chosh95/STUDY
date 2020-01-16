#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
int C, N, M; //N은 egg의 자리수
string E, digit; //egg를 정렬한 문자열 digit
int dp[1 << 14][20][2]; // 14자리, m은 20이하, less여부
const int MOD = 1000000007;

long long price(int idx, int taken, int mod, int less)
{
	if (idx == N) 
		return (less && mod == 0) ? 1 : 0;
	int& res = dp[taken][mod][less];
	if (res != -1) return res;
	res = 0;
	for (int next = 0; next < N; next++) {
		if ((taken & (1 << next)) == 0) {
			if (!less && E[idx] < digit[next]) continue;
			if (next > 0 && digit[next - 1] == digit[next] && (taken & (1 << (next - 1))) == 0) continue;
			int nextTaken = taken | (1 << next);
			int nextMod = (mod * 10 + digit[next] - '0') % M;
			int nextLess = less || E[idx] > digit[next];
			res += price(idx + 1, nextTaken, nextMod, nextLess);
			res %= MOD;
		}
	}
	return res;
}


int main()
{
	cin >> C;
	while (C--) {
		digit.clear();
		memset(dp, -1, sizeof(dp));
		cin >> E >> M;
		vector<int> v;
		long long num = atoll(E.c_str());
		while (num > 0) {
			v.push_back(num % 10);
			num /= 10;
		}
		sort(v.begin(), v.end());
		N = E.size();
		for (int i = 0; i < N; i++) {
			digit += (v[i] + '0');
		}
		cout << price(0, 0, 0, 0) << endl;
	}
}