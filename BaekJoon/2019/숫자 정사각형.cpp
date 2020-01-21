#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
using namespace std;
int N, M, maxlen, res;
int p[51][51];
void check(int x, int y, int cost)
{
	for (int i = 1; i < maxlen; i++) {
		if ( x + i > N || y + i > M ) break;
		if (p[x][y] == p[x][y + i] && p[x][y] == p[x + i][y] && p[x][y] == p[x + i][y + i]) {
			if (res < i + 1) {
				res = i + 1;
			}
		}
	}
}
int main()
{
	cin >> N >> M;
	if (N >= M) maxlen = M;
	else maxlen = N;
	res = 1;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			scanf(" %1d", &p[i][j]);
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			check(i, j, p[i][j]);
		}
	}
	cout << res*res;
}