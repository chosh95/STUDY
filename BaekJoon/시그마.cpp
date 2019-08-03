#include <iostream>
using namespace std;
long long A, B;
int main()
{
	cin >> A >> B;
	long long res;
	if (A > B) {
		long long tmp = B;
		B = A;
		A = tmp;
	}
	res = (B * (B + 1)) / 2 - ((A - 1)*A) / 2;
	cout << res;
}