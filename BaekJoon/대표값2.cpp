#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int p[6], sum = 0;
	for (int i = 0; i < 5; i++) {
		cin >> p[i];
		sum += p[i];
	}
	sort(p, p + 5);
	cout << sum / 5 << "\n" << p[2];
}