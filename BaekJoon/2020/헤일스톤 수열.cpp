#include <iostream>
#include <algorithm>
using namespace std;
int T, N;
int dp[100001];

int hale(int n) {
	int ans = 1;
	while (n != 1) {
		ans = max(ans, n);
		if (n % 2 == 0)
			n /= 2;
		else {
			n *= 3;
			n += 1;
		}
	}
	return ans;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> T;
	while (T--) {
		cin >> N;
		printf("%d\n", hale(N));
	}
}