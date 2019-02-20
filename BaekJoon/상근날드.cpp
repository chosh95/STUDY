#include <iostream>
#include <algorithm>
using namespace std;
int b[3];
int c[2];
int main()
{
	for (int i = 0; i < 3; i++) {
		cin >> b[i];
	}
	for (int i = 0; i < 2; i++) {
		cin >> c[i];
	}
	sort(b, b + 3);
	c[0] = min(c[0], c[1]);
	cout << b[0] + c[0] - 50;
}