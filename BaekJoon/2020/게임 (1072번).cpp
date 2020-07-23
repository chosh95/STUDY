#include <iostream>
#include <algorithm>
using namespace std;

long long X, Y, Z;
long long res = 987654321;

void bisearch() {
	long long lo = 0, hi = 1000000000;
	while (lo <= hi) {
		long long mid = (lo + hi) / 2;
		long long z = ((Y + mid) * 100) / (X + mid);
		if (z > Z) {
			hi = mid - 1;
		}
		else {
			res = mid + 1;
			lo = mid + 1;
		}
	}
}

int main()
{
	cin >> X >> Y;
	Z = (Y*100) / X;
	if (Z >= 99) {
		cout << -1;
		return 0;
	}
	bisearch();
	cout << res;
}