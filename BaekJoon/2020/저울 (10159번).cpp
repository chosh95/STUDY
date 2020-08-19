#include <iostream>
#include <algorithm>
using namespace std;
int p[101][101];
int N, M;

int main()
{
	cin >> N >> M;
	for (int a, b, i = 1; i <= M; i++) {
		cin >> a >> b;
		p[a][b] = 1;
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= N; k++) {
				if (p[j][i] == 1 && p[i][k] == 1) p[j][k] = 1;
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		int cnt = 0;
		for (int j = 1; j <= N; j++) {
			if (j == i) continue;
			if (p[i][j] == 0 && p[j][i]==0) cnt++;
		}
		cout << cnt << "\n";
	}
}