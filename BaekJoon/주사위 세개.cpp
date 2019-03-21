#include <iostream>
#include <algorithm>
using namespace std;
int p[3];
void dice(int cnt)
{
	if (cnt == 1) {
		cout << p[2] * 100;
		return;
	}
	else if (cnt == 2) {
		cout << p[1] * 100 + 1000;
		return;
	}
	else {
		cout << p[1] * 1000 + 10000;
		return;
	}
}
int main()
{
	cin >> p[0] >> p[1] >> p[2];
	sort(p, p + 3);
	int cnt = 1;
	for (int i = 1; i < 3; i++) {
		if (p[i] == p[i - 1])
			cnt++;
	}
	dice(cnt);
	return 0;
}