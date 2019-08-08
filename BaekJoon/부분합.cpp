#include <iostream>
#include <algorithm>
using namespace std;
int p[100002];
int N, S, res = 99999;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> S;
	for (int i = 1; i <= N; i++) cin >> p[i];
	int low = 1, high = 1;
	int sum = p[1];
	int res = 999999;
	while (low <= high && high <= N) {
		if (sum < S) sum += p[++high];
		else if (sum == S) {
			res = min(res, high - low + 1);
			sum += p[++high];
		}
		else if (sum > S) {
			res = min(res, high - low + 1);
			sum -= p[low++];
		}
	}
	if (res == 999999) res = 0;
	cout << res;
}