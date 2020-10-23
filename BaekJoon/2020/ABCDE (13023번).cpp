#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
int N, M;
vector<int> v[2001];
int visit[2001];

bool dfs(int cur, int cnt) {
	if (cnt == 5) return true;

	for (int nx : v[cur]) {
		if (visit[nx] == 1) continue;
		visit[nx] = 1;
		if (dfs(nx, cnt+1)) return true;
		visit[nx] = 0;
	}

	return false;
}

int main()
{
	cin >> N >> M;
	for (int a, b, i = 0; i < M; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	bool isTrue = false;
	for (int i = 0; i < N; i++) {
		visit[i] = 1;
		if (dfs(i, 1)) {
			isTrue = true;
			break;
		}
		visit[i] = 0;
	}

	if (isTrue) cout << "1";
	else cout << "0";
}