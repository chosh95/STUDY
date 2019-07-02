#include <iostream>
#include <algorithm>
using namespace std;
int N, M;
int min6 = 9999, min1 = 9999;
int main()
{
	cin >> N >> M;
	int a, b;
	for (int i = 1; i <= M; i++) {
		cin >> a >> b;
		min6 = min(min6, a);
		min1 = min(min1, b);
	}
	int cost = 0;
	while (N >= 6) {
		if (min6 > 6 * min1) {
			N -= 6;
			cost += 6 * min1;
		}
		else {
			N -= 6;
			cost += min6;
		}
	}
	if (N == 0) {
		cout << cost;
		return 0;
	}
	if (min6 > min1 * N) {
		cost += min1 * N;
	}
	else cost += min6;
	cout << cost;
	return 0;
}
