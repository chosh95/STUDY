#include <iostream>
#include <algorithm>
using namespace std;
long long p[1000001];
long long N, M, res;

void bisect(long long lo, long long hi)
{
	if (lo > hi) return;
	long long mid = (lo + hi) / 2;
	long long sum = 0;
	for (int i = 0; i < N; i++) {
		if (p[i] > mid)
			sum += (p[i] - mid);
	}
	if (sum >= M) {
		if(res<mid) res = mid;
		bisect(mid + 1, hi);
	}
	else bisect(lo, mid - 1);
}

int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> p[i];
	sort(p, p + N);
	bisect(0, p[N-1]);
	cout << res;
}