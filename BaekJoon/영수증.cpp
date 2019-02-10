#include <iostream>
using namespace std;

int main()
{
	int res, tmp;
	cin >> res;
	for (int i = 1; i <= 9; i++) {
		cin >> tmp;
		res -= tmp;
	}
	cout << res;
}