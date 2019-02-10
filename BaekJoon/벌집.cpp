#include <iostream>
using namespace std;

int main()
{
	long long N;
	cin >> N;
	N--;
	int i = 0;
	while (true) {
		N -= (6 * i);
		i++;
		if (N <= 0) break;
	}
	cout << i;
}