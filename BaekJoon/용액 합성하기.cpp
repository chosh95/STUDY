#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
int p[100000 + 1];
int minnum = 100000000 + 1;
bool cmp(int a, int b)
{
	if (abs(a) > abs(b)) return true;
	else return false;
}

int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> p[i];
	sort(p, p + N, cmp);
	int res0, res1;
	for (int i = 0; i < N - 1; i++) {
		if (abs(p[i] + p[i + 1]) < minnum) {
			minnum = abs(p[i] + p[i + 1]);
			res0 = p[i];
			res1 = p[i + 1];
		}
	}
	cout << res0 + res1;
}
