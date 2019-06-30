#include <iostream>
using namespace std;
int A, B, C, D, P;
int main()
{
	int X, Y;
	cin >> A >> B >> C >> D >> P;
	X = P * A;
	Y = B;
	if (P > C)
		Y += (P - C)*D;
	if (X >= Y) cout << Y;
	else cout << X;
	
}