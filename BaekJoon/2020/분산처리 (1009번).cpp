#include <iostream>
using namespace std;
int T, a, b;

int main()
{
	cin >> T;
	while (T--) {
		cin >> a >> b;
		int res = 1;
		for (int i = 1; i <= b; i++) {
			res = (res * a) % 10;
		}
		if (res == 0) cout << 10 << "\n";
		else cout << res << "\n";
	}
}