#include <iostream>
#include <algorithm>
using namespace std;
int p[10];
int main()
{
	int sum = 0;
	for (int i = 0; i < 10; i++) {
		cin >> p[i];
		sum += p[i];
	}
	sort(p, p + 10);
	int cnt = 0, maxcnt = 1, maxnum = p[0];
	for (int i = 1; i < 10; i++) {
		if (p[i] == p[i - 1]) {
			cnt++;
			if (cnt >= maxcnt) {
				maxcnt = cnt;
				maxnum = p[i];
			}
		}
		else cnt = 0;
	}
	cout << sum / 10 << "\n" << maxnum;

}