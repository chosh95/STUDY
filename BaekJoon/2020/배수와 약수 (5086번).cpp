#include <iostream>
using namespace std;
int a, b;

void calc(int a, int b) {
	if (a > b) {
		if (a % b == 0) {
			cout << "multiple\n";
			return;
		}
	}
	else {
		if (b % a == 0) {
			cout << "factor\n";
			return;
		}
	}

	cout << "neither\n";
	return;
}

int main()
{
	while (true) {
		cin >> a >> b;
		if (a == 0 && b == 0) return 0;
		calc(a, b);
	}
}