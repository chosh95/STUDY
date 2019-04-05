#include <iostream>
using namespace std;
long long p[1500001];

int main()
{
	p[1] = 1;
	p[2] = 1;
	long long N;
	cin >> N;
	N %= 1500000;
	for (int i = 3; i <= 1500000; i++)
		p[i] = (p[i - 1] + p[i - 2])%1000000;

	cout << p[N];
}