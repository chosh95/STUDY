#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;

int N;
int p[100001];
int sum = 2 * 100000000;
int res;

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
			res = cur;
		}

		if (cur < 0) left++;
		else if (cur > 0) right--;
		else break;
	}

	cout << res;
}