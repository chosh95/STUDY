#include <iostream>
using namespace std;

int M, N, x, y, max_year;
int gcd(int x, int y)
{
	if (x == 0) return y;
	return gcd(y%x, x);
}

int lcm(int x, int y)
{
	int z = gcd(x, y);
	return (x / z)*y;
}

int main()
{
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int m = lcm(b, d);
	int n = (m / b)*a + (m / d)*c;
	int i = n/gcd(m, n);
	int j = m/gcd(m, n);
	cout << i << " " << j;
}