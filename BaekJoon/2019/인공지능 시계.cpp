#include <iostream>
using namespace std;
int main()
{
	int A, B, C, D;
	cin >> A >> B >> C >> D;
	C += (D % 60);
	B += (D / 60);
	if (C >= 60) {
		B += C / 60;
		C %= 60;
	}
	if (B >= 60) {
		A += B / 60;
		B %= 60;
	}
	if (A >= 24) {
		A %= 24;
	}


	cout << A << " " << B << " " << C;

}