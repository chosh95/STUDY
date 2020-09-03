#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;

int N;
int p[100001];
long long sum = LLONG_MAX;
int res1, res2;

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> p[i];
	sort(p, p + N);

	int left = 0, right = N - 1;
	while (left < right) {
		int cur = p[left] + p[right];
		if (sum > abs(cur)) {
			sum = abs(cur);
			res1 = p[left];
			res2 = p[right];
		}

		if (cur < 0) left++;
		else if (cur > 0) right--;
		else break;
	}

	cout << res1 << " " << res2;
}