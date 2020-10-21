#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int N, M, K;
int p[301][301];
int visit[301][301];

int dfs(int cur, int cnt) {
	if (cur == N) return 0;
	if (cnt == 0) return -987654321;

	if (visit[cur][cnt] != 0) return visit[cur][cnt];

	for (int i = cur + 1; i <= N; i++) {
		if (p[cur][i] == 0) continue;
		visit[cur][cnt] = max(visit[cur][cnt], dfs(i, cnt - 1) + p[cur][i]);
	}

	return visit[cur][cnt];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M >> K;

	for (int a,b,c,i = 1; i <= K; i++) {
		cin >> a >> b >> c;
		p[a][b] = max(p[a][b], c);
	}

	cout << dfs(1, M - 1);
}