#include <iostream>
using namespace std;
int p[101];

int gcd(int a, int b)
{
	if (b == 0) return a;
	else return gcd(b, a%b);
}

void cal(int a, int b)
{
	int c = gcd(a, b);
	cout << a / c << "/" << b / c << "\n";
}

int main()
{
	int N;
	cin >> N;
	cin >> p[0];
	for (int i = 1; i < N; i++) {
		cin >> p[i];
		cal(p[0], p[i]);
	}
	return 0;
}