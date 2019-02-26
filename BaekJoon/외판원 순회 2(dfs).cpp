#include <iostream>
#include <algorithm>
using namespace std;

int N, res = 0xfffffff;
int p[11][11];
int visit[11];

void dfs(int here,int there, int sum,int cnt)
{
	if (cnt == N-1) {
		if (p[there][here] == 0) return;
		res = min(res, sum + p[there][here]);
		return;
	}
	for (int i = 1; i <= N; i++) {
		if (visit[i] == 0 && p[there][i]) {
			visit[i] = 1;
			dfs(here, i, sum + p[there][i], cnt + 1);
			visit[i] = 0;
		}
	}
}

int main()
{
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> p[i][j];
		}
	}

	for (int i = 1; i <= N; i++) {
			visit[i] = 1;
			dfs(i,i,0,0);
			visit[i] = 0;
	}
	cout << res;
}