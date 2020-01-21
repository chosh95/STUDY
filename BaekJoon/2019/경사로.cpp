#include <iostream>
#include <algorithm>
using namespace std;
int N, L, res;
int a[102][102], b[102][102];

void check(int n, int p[102][102]) {
	bool visit[101] = { 0 };
	int cur = p[n][1];
	for (int i = 1; i <= N; i++) {
		if (p[n][i] == cur) continue;
		if (abs(p[n][i] - cur) > 1) return;
		if (p[n][i] < cur) { //다음 값이 더 작은 경우
			int tmp = -1;
			for (int j = i; j <= i + L - 1; j++) {
				if (j > N || visit[j]) return;
				visit[j] = true;
				if (tmp == -1) {
					tmp = p[n][j];
					continue;
				}
				if (tmp != -1 && p[n][j] != tmp) return;
			}
			i = i + L - 1;
			if (i > N) break;
		}
		else { // 더 큰 경우
			int tmp = -1;
			for (int j = i - 1; j >= i - L; j--) {
				if (j < 1 || visit[j]) return;
				visit[j] = true;
				if (tmp == -1) {
					tmp = p[n][j];
					continue;
				}
				if (tmp != -1 && p[n][j] != tmp) return;
			}
		}
		cur = p[n][i];
	}
	res+=1;
}

int main()
{
	cin >> N >> L;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> a[i][j];
			b[j][i] = a[i][j]; //a행렬을 transpose
		}
	}
	for (int i = 1; i <= N; i++) {
		check(i, a);
		check(i, b);
	}
	cout << res;
}
