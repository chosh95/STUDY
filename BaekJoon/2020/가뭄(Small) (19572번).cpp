#include <iostream>
#include <algorithm>
using namespace std;
double d1, d2, d3;
double a, b, c;

int main()
{
	cin >> d1 >> d2 >> d3;
	cout << fixed;
	cout.precision(1);
	a = (d1 + d2 - d3) / 2;
	b = (d1 - d2 + d3) / 2;
	c = (d2 + d3 - d1) / 2;
	if (a <= 0 || b<=0 || c<=0) {
		cout << "-1";
		return 0;
	}
	else {
		cout << "1\n";
		cout << a << " " << b << " " << c;
	}
}