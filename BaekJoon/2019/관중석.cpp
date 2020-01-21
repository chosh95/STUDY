#include <iostream>
#include <map>
using namespace std;
bool c[2001][2001];
int gcd(int a, int b)
{
	if (b == 0) return a;
	else gcd(b, a%b);
}
int main()
{
	int D1, D2, cnt = 0;
	cin >> D1 >> D2;
	for (int i = D1; i <= D2; i++) {
		for (int j = 1; j <= i; j++) {
			int g = gcd(i, j);
			if (!c[j / g][i / g])cnt++, c[j/g][i/g]=true;
		}
	}
	cout << cnt;
}