#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int p[3];
	while (true) {
		cin >> p[0] >> p[1] >> p[2];
		if (p[0] == 0 && p[1] == 0 && p[2] == 0) break;
		sort(p, p + 3);
		if (p[0] * p[0] + p[1] * p[1] == p[2] * p[2]) cout << "right\n";
		else cout << "wrong\n";
	}
	return 0;
}