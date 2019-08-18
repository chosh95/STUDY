#include <iostream>
using namespace std;
int N;

int main()
{
	cin >> N;
	bool tmp = true;
	while (N > 1) {
		if (N % 2 != 0) {
			tmp = false;
			break;
		}
		N /= 2;
	}
	if (tmp) cout << "1";
	else cout << "0";
}