#include <iostream>
using namespace std;

int main()
{
	int a, b;
	while (true) {
		cin >> a >> b;
		if (a == 0 && b == 0) return 0;
		else {
			if (a > b) cout << "Yes\n";
			else cout << "No\n";
		}
	}
}