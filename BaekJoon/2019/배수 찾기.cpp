#include <iostream>
using namespace std;
int n;

int main()
{
	cin >> n;
	while (true) {
		int tmp;
		cin >> tmp;
		if (tmp == 0) return 0;
		if (tmp < n || tmp % n != 0)
			cout << tmp << " is NOT a multiple of " << n << ".\n";
		else if (tmp % n == 0)
			cout << tmp << " is a multiple of " << n << ".\n";
	}
}