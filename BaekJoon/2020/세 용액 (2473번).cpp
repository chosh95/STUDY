#include <iostream>
#include <algorithm>
using namespace std;
int N;
long long p[5001];
long long sum = (long long)1000000000 * 3;

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> p[i];
	sort(p, p + N);

	long long r, e, s;

	for (int i = 0; i < N - 2; i++) {
		long long a = p[i];
		int left = i + 1;
		int right = N - 1;

		while (left < right) {
			long long cur = a + p[left] + p[right];

			if (sum > abs(cur)) {
				sum = abs(cur);
				r = a;
				e = p[left];
				s = p[right];
			}

			if (cur < 0) left++;
			else if (cur > 0) right--;
			else {
				i == N; break;
			}
		}
	}

	cout << r << " " << e << " " << s;
}