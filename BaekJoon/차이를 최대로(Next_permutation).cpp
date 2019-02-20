#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int N;
	cin >> N;
	int p[10];
	for (int i = 0; i < N; i++) cin >> p[i];
	sort(p, p + N);

	int maxnum = 0;

	do {
		int tmp = 0;
		for (int i = 0; i < N - 1; i++) {
			tmp += abs(p[i] - p[i + 1]);
		}
		if (tmp > maxnum) maxnum = tmp;
	} while (next_permutation(p, p + N));
	cout << maxnum;
}