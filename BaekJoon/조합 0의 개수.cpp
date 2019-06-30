#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
ll N, M;
pair<ll,ll> combinate(ll num)
{
	ll t = 0, f = 0;
	for (ll i = 2; i <= num; i *= 2) {
		t += num / i;
	}
	for (ll i = 5; i <= num; i *= 5) {
		f += num / i;
	}
	return { t,f };
}

int main()
{
	cin >> N >> M;
	pair<ll, ll> a = combinate(N);
	pair<ll, ll> b = combinate(M);
	pair<ll, ll> c = combinate(N - M);
	ll t = a.first - b.first - c.first;
	ll f = a.second - b.second - c.second;
	cout << min(t, f);
}