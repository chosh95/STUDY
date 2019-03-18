#include <iostream>
using namespace std;
int rev(int n)
{
	if (n >= 1000) {
		int a, b, c, d;
		a = n / 1000;
		n %= 1000;
		b = n / 100;
		n %= 100;
		c = n / 10;
		d = n % 10;
		return d * 1000 + c * 100 + b * 10 + a;
	}
	else if (n >= 100) {
		int tmp;
		tmp = n % 10;
		n /= 10;
		tmp *= 10;
		tmp += n % 10;
		tmp *= 10;
		tmp += n / 10;
		return tmp;
	}
	else if (n >= 10) {
		int tmp;
		tmp = n % 10;
		tmp *= 10;
		tmp += n / 10;
		return tmp;
	}
	else return n;
}
int main()
{
	int X, Y;
	cin >> X >> Y;
	X = rev(X);
	Y = rev(Y);
	cout << rev(X + Y);
}