#include <iostream>
using namespace std;
char c[51][51];

int chess(int a, int b)
{
	char tmp = c[a][b];
	int res = 0;
	for (int i = a; i < a + 8; i++) {
		for (int j = b; j < b + 8; j++) {
			if ((i - a + j - b) % 2 == 0 && tmp != c[i][j]) res++;
			if ((i - a + j - b) % 2 == 1 && tmp == c[i][j]) res++;
		}
	}
	if (res >= 32) res = 64 - res;
	return res;
}

int main()
{
	int N, M;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> c[i][j];
		}
	}
	int res = 99;
	for (int i = 1; i <= N - 7; i++) {
		for (int j = 1; j <= M - 7; j++) {
			int tmp = chess(i, j);
			if (res > tmp) res = tmp;
		}
	}
	cout << res;
}
