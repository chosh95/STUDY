#include <iostream>
using namespace std;

int main()
{
	int p[10];
	int mn = 0, mi = 0;
	for (int i = 1; i <= 9; i++) {
		cin >> p[i];
		if (p[i] > mn) {
			mn = p[i];
			mi = i;
		}
	}
	cout << mn << "\n" << mi;
}