#include <iostream>
using namespace std;

int main()
{
	int N, F;
	cin >> N >> F;
	int tmp = N % 100;
	N -= tmp;
	for (int i = 0; i <= 99; i++) {
		if (N%F == 0) {
			if (i < 10) cout << "0" << i;
			else cout << i;
			return 0;
		}
		N += 1;
	}
}