#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int N, K, res;
	cin >> N >> K;
	int l = 1, r = K, mid;
	while (l <= r) {
		mid = (l + r) / 2;
		int cnt = 0;
		for (int i = 1; i <= N; i++) {
			cnt += min(mid / i, N);
		}
		if (cnt < K) l = mid + 1;
		else {
			res = mid;
			r = mid - 1;
		}
	}
	cout << res;
}