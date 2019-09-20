#include <iostream>
#define MIN(a, b) ((a)<(b) ? (a) : (b))
using namespace std;
int A, B, C, D;
int main()
{
	int res = 0;
	cin >> A >> B >> C >> D;
	res = MIN(A + D, C + B);
	cout << res;
}