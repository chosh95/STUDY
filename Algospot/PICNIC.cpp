#include <iostream>
#include <memory.h>
using namespace std;
int C, N, M, res = 0;
int f[11][11]; //f[i][j] == 1이면 i와 j는 친구
int hasFriend[11]; //hasFrined[i] = 1이면 i는 친구가 있다.

void dfs()
{
	int first = -1;
	for (int i = 0; i < N; i++) {
		if (hasFriend[i]==0) {
			first = i;
			break;
		}
	}
	if (first == -1) {
		res++;
		return;
	}
	for (int i = first+1; i < N; i++) {
		if (hasFriend[i]==0 && hasFriend[first]==0 && f[i][first]==1) {
			hasFriend[i] = hasFriend[first] = 1;
			dfs();
			hasFriend[i] = hasFriend[first] = 0;
		}
	}
}


int main()
{
	cin >> C;
	while (C--) {
		memset(f, 0, sizeof(f));
		memset(hasFriend, 0, sizeof(hasFriend));
		res = 0;
		cin >> N >> M;
		for (int a, b, i = 1; i <= M; i++) {
			cin >> a >> b;
			f[a][b] = f[b][a] = 1;
		}
		dfs();
		cout << res << "\n";
	}
}