#include <iostream>
using namespace std;

int main()
{
	int p[5],res=0;
	for (int i = 0; i < 5; i++) {
		cin >> p[i];
		res += (p[i] * p[i]);
	}
	cout << res % 10;
}