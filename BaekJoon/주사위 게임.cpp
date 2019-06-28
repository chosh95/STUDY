#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int N;
	cin >> N;
	int res = 0;
	while (N--) {
		int a, b, c, tmp;
		cin >> a >> b >> c;
		if (a == b && b == c) tmp = 10000 + a * 1000;
		else if (a == b || a==c) tmp = 1000 + 100 * a;
		else if (b == c) tmp = 1000 + 100 * b;
		else {
			int maxnum = max(max(a, b), c);
			tmp = 100 * maxnum;
		}
		if (res < tmp) res = tmp;
	}
	cout << res;
}