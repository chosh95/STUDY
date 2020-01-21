#include <iostream>
using namespace std;
int N;
int main()
{
	cin >> N;
	while (N--) {
		int r, c, e;
		cin >> r >> c >> e;
		if (r < c - e) cout << "advertise\n";
		else if (r == c - e) cout << "does not matter\n";
		else cout << "do not advertise\n";
	}
}