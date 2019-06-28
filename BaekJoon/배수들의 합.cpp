#include <iostream>
using namespace std;
int p[1001], k[1001];
int N, M;
int main()
{
	cin >> N >> M;
	for (int i = 1; i <= M; i++) cin >> k[i];

	int res = 0;
	for (int i = 1; i <= M; i++) {
		int cur = k[i];
		if (p[cur] == 1) continue;
		for (int j = cur; j <= N; j += cur) {
			if (p[j] == 1) continue;
			p[j] = 1;
			res += j;
		}
	}
	cout << res;
}