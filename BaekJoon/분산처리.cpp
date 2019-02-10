#include <iostream>
using namespace std;

int main()
{
	int T;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		int a, b;
		cin >> a >> b;
		int c = a;
		for (int i = 1; i < b; i++) {
			c *= a;
			c %= 10;
		}
		if (c == 0) cout << 10 << endl;
		else cout << c << endl;
	}
}