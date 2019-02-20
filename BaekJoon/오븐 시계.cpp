#include <iostream>
using namespace std;
int main()
{
	int A, B;
	int C;
	cin >> A >> B >> C;
	B += C;
	int count = 0;
	while (true) {
		if (B >= 60) {
			B -= 60;
			count++;
		}
		else break;
	}
	A += count;
	if (A >= 24) A -= 24;
	cout << A << " " << B;
}