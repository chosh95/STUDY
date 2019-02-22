#include <iostream>
#include <math.h>
using namespace std;
typedef long long ll;
ll A, B, C, D;

ll cal(ll a, ll b)
{
	ll tmp = b;
	int cnt = 0;
	while (tmp) {
		tmp /= 10;
		cnt++;
	}
	a = a * pow(10, cnt);
	return a + b;
}

int main()
{
	cin >> A >> B >> C >> D;
	cout << cal(A, B) + cal(C, D);
}