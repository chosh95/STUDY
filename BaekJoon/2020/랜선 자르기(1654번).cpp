#include <iostream>
#include <algorithm>
using namespace std;
int p[10001];
int N, K;

int bisect()
{
	long long lo = 1, hi = p[K - 1];
	while (lo <= hi) {
		long long mid = (lo + hi) / 2;
		int tmp = 0;
		for (int i = 0; i < K; i++)
			tmp += (p[i] / mid);

		if (tmp < N)
			hi = mid - 1;
		else
			lo = mid + 1;
	}
	return hi;
}

int main()
{
	cin >> K >> N;
	for (int i = 0; i < K; i++) cin >> p[i];
	sort(p, p + K);
	cout << bisect() << endl;
}