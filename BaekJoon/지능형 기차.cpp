#include <iostream>
using namespace std;

int main()
{
	int A, B,sum=0,max=0;
	for (int i = 1; i <= 4; i++) {
		cin >> A >> B;
		sum -= A;
		sum += B;
		if (sum > max) max = sum;
	}
	cout << max;
}