#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory.h>
using namespace std;
int C, N;
string W, S;
int dp[101][101];

int wildcard(int wpos, int spos)
{
	int &ret = dp[wpos][spos];
	if (ret != -1) return ret;

	if(wpos < W.size() && spos < S.size() &&(W[wpos]=='?' || W[wpos]==S[spos])) 
		return ret = wildcard(wpos + 1, spos + 1);
	if (wpos == W.size() && spos == S.size())
		return ret = 1;
	if (W[wpos] == '*') {
		if (wildcard(wpos + 1, spos) || (spos<S.size() && wildcard(wpos, spos + 1))) {
			return ret = 1;
		}
	}
	return ret = 0;
}
int main()
{
	cin >> C;
	while (C--) {
		cin >> W;
		cin >> N;
		vector<string> v;
		while (N--) {
			cin >> S;
			memset(dp, -1, sizeof(dp));
			if (wildcard(0, 0) == 1) v.push_back(S);
		}
		sort(v.begin(), v.end());
		for (int i = 0; i < v.size(); i++)
			cout << v[i] << "\n";
	}
}
