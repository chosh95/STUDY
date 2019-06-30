#include <iostream>
#include <cmath>
#include <map>
using namespace std;
typedef long long ll;
map<ll, ll> m;
ll N, P, Q;

ll cal(ll n)
{
	if (n == 0) return 1;
	else if (m[n] != 0) return m[n];
	else return m[n] = cal(n / P) + cal(n / Q);
}

int main()
{
	cin >> N >> P >> Q;
	cout<<cal(N);
}