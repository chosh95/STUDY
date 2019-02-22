#include <iostream>
using namespace std;

int main()
{
	int tmp=0, res=0, a, b;
	for (int i = 1; i <= 10; i++) {
		cin >> a >> b;
		tmp -= a;
		tmp += b;
		if (res < tmp) res = tmp;
	}
	cout << res;
}