#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int dp[2001][2001];
vector<int> l;
vector<int> r;
//¼ø¼­´ë·Î left index, right index, current Score, left Ä«µåµ¦, right Ä«µåµ¦
int dfs(int li, int ri)
{
	if (li >= l.size() || ri >= r.size()) return 0;
	if (dp[li][ri] > 0) return dp[li][ri];
	
	dp[li][ri] = max(dfs(li + 1, ri + 1), dfs(li + 1, ri));
	if (l[li] > r[ri]) dp[li][ri] = max(dp[li][ri], r[ri] + dfs(li, ri + 1));
	return dp[li][ri];
}

int solution(vector<int> left, vector<int> right) {
	int answer = 0;
	memset(dp, -1, sizeof(dp));
	l = left;
	r = right;
	answer = dfs(0, 0);
	return answer;
}

int main()
{
	cout << solution({ 3,2,5 }, { 2,4,1 });
}