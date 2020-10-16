#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

int mul(int a, int b) {
	int sum = 0, tmp = 0;
	while (b > 0) {
		sum += (a << (int)log2(b));
		b = b % (1 << (int)log2(b));
		
	}
	return sum;
}

int main()
{
	cout << mul(3, 20);
}