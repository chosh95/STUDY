#include <iostream>
using namespace std;
int N, S, res;
int p[21];

void dfs(int idx, int sum) {
	if (idx > N) return;
	if (sum == S && idx==N) {
		res++;
		return;
	}

	dfs(idx + 1, sum + p[idx+1]);
	dfs(idx + 1, sum);
}

int main()
{
	cin >> N >> S;
	for (int i = 1; i <= N; i++) cin >> p[i];
	res = 0;
	dfs(0, 0);

	if (S == 0) res--;
	cout << res;
}