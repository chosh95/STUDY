#include <iostream>
using namespace std;
long long p[61];

int main()
{
	int H;
	cin >> H;
	p[0] = p[1] = 1;
	for (int i = 2; i <= H; i++) {
		if (i % 2 == 0) p[i] = p[i - 1] * 2 + 1;
		else p[i] = p[i - 1] * 2 - 1;
	}
	cout << p[H];
}