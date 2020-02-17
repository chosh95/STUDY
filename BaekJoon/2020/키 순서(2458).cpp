#include <iostream>
#include <vector>
using namespace std;
int N, M;
const int INF = 987654321;
int p[501][501]; //p[a][b] : a보다 b가 크다.

int main()
{
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			if (i != j) p[i][j] = INF; //모두 무한대로 초기화
	
	for (int a, b, i = 0; i < M; i++) {
		cin >> a >> b;
		p[a][b] = 1;
	}

	for (int k = 1; k <= N; k++) { //플로이드-와샬
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (p[i][j] > p[i][k] + p[k][j]) //a보다 b가 크고 b보다 c가 크면
					p[i][j] = 1; //c는 a보다 크다.
			}
		}
	}
	
	int res = 0; //결과값
	for (int i = 1; i <= N; i++) {
		int cnt = 0; // 나보다 크거나 작은 사람의 수
		for (int j = 1; j <= N; j++) {
			if (i == j) continue; // 나 자신은 제외
			if (p[i][j] != INF || p[j][i] != INF) cnt++; // 사람수++
		}
		if (cnt == N - 1) res++; // 그 사람수가 N-1이면 내 순서를 알 수 있다.
	}
	cout << res;
}