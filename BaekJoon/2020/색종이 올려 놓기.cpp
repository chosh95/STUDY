#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
vector<pair<int, int>> v;
int N, res;
int dp[101];

bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.first == b.first)
		return a.second > b.second;
	return a.first > b.first;
}

bool isPossible(pair<int, int> a, pair<int, int> b) {
	if (a.first >= b.first && a.second >= b.second) return true;
	return false;
}

int dfs(int idx) {

	if (idx >= N + 1)
		return 0;

	if (dp[idx] != -1) return dp[idx];
	int tmp = 0;

	for(int i=idx + 1;i<=N + 1;i++)
		if (i==N+1 || isPossible(v[idx],v[i]))
			tmp = max(tmp, dfs(i) + 1);

	dp[idx] = tmp;

	return dp[idx];
}

int main()
{
	cin >> N;
	v.push_back({ 1000,1000 });
	for (int x, y, i = 1; i <= N; i++) {
		cin >> x >> y;
		if (x < y) swap(x, y);
		v.push_back({ x,y });
	}
	sort(v.begin(), v.end(), cmp);
	memset(dp, -1, sizeof(dp));
	cout << dfs(0) - 1;

}