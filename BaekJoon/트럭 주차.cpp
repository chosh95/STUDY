#include <iostream>
using namespace std;
int A, B, C;
int p[101];

int main()
{
	cin >> A >> B >> C;
	for (int i = 0; i < 3; i++) {
		int a, b;
		cin >> a >> b;
		for (int i = a; i < b; i++) {
			p[i]++;
		}
	}
	int res = 0;
	for (int i = 1; i <= 100; i++) {
		if (p[i] == 1) res += A;
		else if (p[i] == 2) res += 2*B;
		else if (p[i] == 3) res += 3*C;
	}
	cout << res;
}