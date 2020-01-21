#include <iostream>
using namespace std;
int main()
{
	int N, a, b, res=1;
	cin >> N >> a >> b;
	while (true) {
		if ((b - a == 1 && b % 2 == 0) || (a - b == 1 && a % 2 == 0)) {
			cout << res;
			break;
		}
		res++;
		a = a / 2 + a % 2;
		b = b / 2 + b % 2;
	}
}