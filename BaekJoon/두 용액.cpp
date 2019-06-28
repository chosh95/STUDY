#include <iostream>
#include <algorithm>
using namespace std;
int p[100002];
bool cmp(int a, int b)
{
	return abs(a) > abs(b);
}
int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> p[i];
	}
	sort(p, p + N, cmp);
	int res = 2 * 1000000000;
	int a = 0, b = 0;
	for (int i = 0; i < N - 1; i++) {
		int tmp = abs(p[i] + p[i + 1]);
		if (res > tmp) {
			res = tmp;
			a = p[i];
			b = p[i + 1];
		}
	}
	if (a > b) cout << b << " " << a;
	else cout << a << " " << b;
}