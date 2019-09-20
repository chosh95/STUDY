#include <iostream>
#include <algorithm>
using namespace std;
int p[11];
int main()
{
	int N;
	cin >> N;
	while (N--) {
		for (int i = 0; i < 10; i++)cin >> p[i];
		sort(p, p + 10);
		cout << p[7] << "\n";
	}
}