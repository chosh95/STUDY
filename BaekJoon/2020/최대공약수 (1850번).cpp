#include <iostream>
using namespace std;
long long a, b;

long long gcd(long long a, long long b)
{
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main()
{
	cin >> a >> b;
	for (int i = 0; i < gcd(a, b); i++)
		cout << "1";
}