#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
int N, res = 2147483647;
int p[100001];

bool cmp(int a, int b) {
	return abs(a) < abs(b);
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> p[i];
	sort(p, p + N, cmp);
	int res1, res2;
	for (int i = 0; i < N - 1; i++) {
		if (abs(p[i] + p[i + 1]) < res) {
			res = abs(p[i] + p[i + 1]);
			res1 = p[i];
			res2 = p[i + 1];
		}
	}
	if (res1 > res2)
		swap(res1, res2);
	cout << res1 << " " << res2;
}