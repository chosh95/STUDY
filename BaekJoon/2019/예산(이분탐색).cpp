#include <iostream>
using namespace std;
int p[10001];
int N, res, M;
void binary(int a, int b)
{
	int m = (a + b) / 2;
	if (m <= a || m >= b) return;
	int sum = 0;
	for (int i = 0; i <= N; i++) {
		if (p[i] < m) sum += p[i];
		else sum += m;
	}
	if (sum <= M) {
		if (res < m) res = m;
		binary(m, b);
	}
	else binary(a, m);
}
int main()
{
	int sum=0,maxnum = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> p[i];
		sum += p[i];
		if (maxnum < p[i]) maxnum = p[i];
	}
	cin >> M;
	if (sum <= M) cout << maxnum;
	else {
		binary(0, maxnum);
		cout << res;
	}
}