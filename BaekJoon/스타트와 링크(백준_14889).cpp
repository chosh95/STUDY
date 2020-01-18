#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int N, sum = 0, res = 987654321;
int p[21][21];
bool s[21];
void dfs(int start, int cnt)
{
	if (cnt == N / 2) {
		int teamA = 0;
		for (int i = 1; i <= N; i++) {
			if (s[i]) continue;
			for (int j = i + 1; j <= N; j++) {
				if (s[j]) continue;
				teamA += p[i][j];
				teamA += p[j][i];
			}
		}

		int teamB = 0;
		for (int i = 1; i <= N; i++) {
			if (!s[i]) continue;
			for (int j = i + 1; j <= N; j++) {
				if (!s[j]) continue;
				teamB += p[i][j];
				teamB += p[j][i];
			}
		}
		res = min(res, abs(teamA - teamB));
		return;
	}

	for (int i = start+1; i <= N; i++) {
		if (s[i]) continue;
		s[i] = true;
		dfs(i, cnt + 1);
		s[i] = false;
	}
	return;
}

int main()
{
	cin >> N;
	memset(s, false, sizeof(s));
	for (int i = 1; i <= N; i++) 
		for (int j = 1; j <= N; j++) 
			cin >> p[i][j];
	dfs(0, 0);
	cout << res;
}