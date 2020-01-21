#include <iostream>
using namespace std;
int p[43];

int main()
{
	int tmp;
	for (int i = 1; i <= 10; i++) {
		cin >> tmp;
		p[tmp % 42] = 1;
	}
	int cnt = 0;
	for (int i = 0; i <= 41; i++) {
		if (p[i] == 1) cnt++;
	}
	cout << cnt;
}