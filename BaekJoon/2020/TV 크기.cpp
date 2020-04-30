#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	int c, a, b;
	double por, aRes, bRes;
	cin >> c >> a >> b;
	por = sqrt(a * a + b * b);
	por = c / por;
	cout << (int)(por * a) << " " << (int)(por * b);
}