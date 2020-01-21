#include <iostream>
using namespace std;
int gcd(int a, int b) 
{
	if (b == 0) return a;
	else gcd(b, a%b);
}
int lcm(int a, int b)
{
	int tmp = gcd(a, b);
	return a * b / tmp;
}
int main()
{
	int T;
	cin >> T;
	while (T--) {
		int a, b;
		cin >> a >> b;
		cout << lcm(a, b) << " " << gcd(a, b) << "\n";
	}
}