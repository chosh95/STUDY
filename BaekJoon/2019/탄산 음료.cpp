#include <iostream>
using namespace std;
int e, c, f;
int cur, res;

int main()
{
	cin >> e >> c >> f;
	cur = e + c;
	while (true) {
		res += cur / f;
		cur = cur / f + cur % f;
		if (cur < f) break;
	}
	cout << res;
	return 0;
}