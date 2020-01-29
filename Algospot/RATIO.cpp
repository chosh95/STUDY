#include <iostream>
#include <cmath>
using namespace std;

int T, origin;
long long N, M;
long long L = 2000000000;

bool decision(long long x)
{
	int new_num = (100 * (M + x)) / (N + x);
	return origin + 1 <= new_num;
}

int optimize()
{
	origin = (100 * M) / N;
	if (origin == (100 * (M + L) / (N + L))) return -1;

	long long lo = 0, hi = L;
	while (lo + 1 < hi) {
		long long mid = (lo + hi) / 2;
		if (decision(mid))
			hi = mid;
		else
			lo = mid;
	}
	return hi;
}

int main()
{
	cin >> T;
	while (T--) {
		cin >> N >> M;
		cout << optimize() << endl;
	}
}