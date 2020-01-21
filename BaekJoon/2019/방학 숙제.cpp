#include <iostream>
using namespace std;
int L, A, B, C, D;
int main()
{
	cin >> L >> A >> B >> C >> D;
	int res;
	int a = A / C;
	if (A%C != 0) a++;
	int b = B / D;
	if (B%D != 0) b++;
	if (a >= b) res = L - a;
	else res = L - b;
	cout << res;
}