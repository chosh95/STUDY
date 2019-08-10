#include <iostream>
#include <memory.h>
using namespace std;
int N, S, M;
int p[102];
int dp[102][1102];
void dfs(int pos, int vol)
{
	if (dp[pos][vol] != 0) return;
	dp[pos][vol] = 1;
	if (pos == N) return;
	int high = vol + p[pos+1];
	int low = vol - p[pos+1];
	if (high <= M) 
		dfs(pos + 1, high);
	if (low >= 0) 
		dfs(pos + 1, low);
	
	return;
}
int main()
{
	cin >> N >> S >> M;
	for (int i = 1; i <= N; i++) cin >> p[i];
	dfs(0, S);

	int res = -1;
	for (int i = M; i >= 0; i--) {
		if (dp[N][i]==1) {
			res = i;
			break;
		}
	}
	cout << res;
	return 0;
}