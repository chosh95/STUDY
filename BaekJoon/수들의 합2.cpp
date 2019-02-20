#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
int p[10001];
int main()
{
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++) scanf("%d",&p[i]);
	long long res = 0;
	for (int i = 0; i < N ; i++) {
		long long tmp = p[i];
		if (tmp == M) {
			res++;
			continue;
		}
		for (int j = i + 1; j < N; j++) {
			tmp += p[j];
			if (tmp == M) res++;
			else if (tmp > M) break;
		}
	}
	cout << res;
}