#include <iostream>
using namespace std;
int A, B, C;

int main()
{
	cin >> A >> B >> C;
	if (A == 60 && B == 60 && C == 60) cout << "Equilateral";
	else if (A + B + C == 180) {
		if (A == B || A == C || B == C) cout << "Isosceles";
		else cout << "Scalene";
	}
	else cout << "Error";
}