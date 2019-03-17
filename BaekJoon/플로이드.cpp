#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#define INF 9999999999999
int N;
long long p[101][101];

int main()
{
	int M, a, b, c;
	cin >> N >> M;
	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= N; j++){
			if (i != j)
				p[i][j] = INF;
		}
	}
	for (int i = 1; i <= M; i++) {
		scanf("%d%d%d", &a, &b, &c);
		if (p[a][b] > c) p[a][b] = c;
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= N; k++) {
				if (p[j][k] > p[j][i] + p[i][k])
					p[j][k] = p[j][i] + p[i][k];
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (p[i][j] == INF) cout << "0 ";
			else cout << p[i][j] << " ";
		}
		cout << "\n";
	}
}