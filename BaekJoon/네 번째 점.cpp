#include <iostream>
using namespace std;

int main()
{
	pair<int, int> a[2], b[2];
	cin >> a[0].first >> b[0].first;
	a[0].second = 1, b[0].second = 1;
	a[1].second = 0, b[1].second = 0;
	int c, d;
	for (int i = 1; i <= 2; i++) {
		cin >> c >> d;
		if (a[0].first == c) a[0].second += 1;
		else {
			a[1].first = c;
			a[1].second += 1;
		}
		if (b[0].first == d) b[0].second += 1;
		else {
			b[1].first = d;
			b[1].second += 1;
		}
	}
	if (a[0].second == 1) cout << a[0].first << " ";
	else cout << a[1].first << " ";

	if (b[0].second == 1) cout << b[0].first;
	else cout << b[1].first;
}