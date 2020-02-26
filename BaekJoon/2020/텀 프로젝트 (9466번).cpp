#include <iostream>
#include <cstring>
using namespace std;
int T, N;
int p[100001];
int first[100001];
int visit[100001];

int dfs(int start, int x, int cnt)
{
	visit[x] = cnt; //방문회수
	first[x] = start; //시작점 기록
	int nx = p[x];
	if (visit[nx] == 0) return dfs(start, nx, cnt + 1); //방문안했으면 방문
	else if (first[nx] == start) return cnt - visit[nx] + 1; //방문한점이면 cycle의 수 반환.
	else return 0;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;
	while (T--) {
		cin >> N;
		memset(p, 0, sizeof(p));
		memset(first, 0, sizeof(first));
		memset(visit, 0, sizeof(visit));
		for (int i = 1; i <= N; i++) cin >> p[i];

		int res = 0;
		for (int i = 1; i <= N; i++) {
			if (visit[i] == 0) {
				res += dfs(i, i, 1);
			}
		}
		cout << N - res << "\n";
	}
}