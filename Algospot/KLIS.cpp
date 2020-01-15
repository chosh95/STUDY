#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
int C, N, K;
int p[502]; //원본 배열
int len[502]; //i에서 시작하는 최장 길이를 저장하는 dp 배열
int cnt[502]; //i에서 시작하는 최장 길이 수열의 수를 저장하는 dp 배열 
const int MAX = 2000000000 + 1;
int lis(int start)
{
	int& res = len[start+1];
	if (res != -1) return res;
	res = 1;
	for (int i = start + 1; i < N; i++) {
		if (start == -1 || p[i] > p[start]) {
			res = max(res, lis(i)+1);
		}
	}
	return res;
}
int count(int start)
{
	if (lis(start) == 1) return 1;
	int& res = cnt[start+1];
	if (res != -1) return res;
	res = 0;
	for (int i = start + 1; i < N; i++) {
		if ((start == -1 || p[i] > p[start]) && lis(start) == lis(i) + 1) {
			res = min<long long>(MAX, (long long)res + count(i));
		}
	}
	return res;
}

void reconstruct(int start, int skip, vector<int>& ans)
{
	if (start != -1) ans.push_back(p[start]);
	vector<pair<int, int>> followers;
	for (int i = start + 1; i < N; i++) {
		if ((start == -1 || p[start] < p[i]) && lis(start) == lis(i) + 1)
			followers.push_back({ p[i],i });
	}
	sort(followers.begin(), followers.end());
	for (int i = 0; i < followers.size(); i++) {
		int idx = followers[i].second;
		int cnttmp = count(idx);
		if (cnttmp <= skip)
			skip -= cnttmp;
		else {
			reconstruct(idx, skip, ans);
			break;
		}
	}
}
int main()
{
	cin >> C;
	while (C--) {
		cin >> N >> K;
		memset(len, -1, sizeof(len));
		memset(cnt, -1, sizeof(cnt));
		for (int i = 0; i < N; i++) cin >> p[i];
		cout << lis(-1) - 1 << endl;
		vector<int> ans;
		reconstruct(-1, K - 1, ans);
		for (int i = 0; i < ans.size(); i++)
			cout << ans[i] << " ";
		cout << endl;
	}
}
