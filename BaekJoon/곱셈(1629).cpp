#include <iostream>
using namespace std;
typedef long long ll;
ll A, B, C;
ll power(ll a, ll b)
{
	if (b == 0) return 1;
	else if (b == 1) return a;
	if (b % 2 == 1) {
		return power(a, b - 1) * a;
	}
	else {
		ll tmp = power(a, b / 2);
		tmp %= C;
		return (tmp*tmp) % C;
	}
}
int main()
{
	cin >> A >> B >> C;
	cout<< (power(A, B) % C);
}