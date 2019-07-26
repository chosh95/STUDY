#include <iostream>
using namespace std;
int N, M, res;
int p[101];
void dfs(int idx, int count, int sum)
{
	if (count == 3) {
		if(res<sum && sum<=M) res = sum;
		return;
	}
	if (idx >= N || sum > M) return;
	dfs(idx + 1, count + 1, sum + p[idx + 1]);
	dfs(idx + 1, count, sum);
}
int main()
{
	cin >> N >> M;
	for (int i = 1; i <= N; i++) cin >> p[i];
	dfs(0, 0, 0);
	cout << res;
}