#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	int T;
	cin >> T;
	string a, b;
	while (T--) {
		cin >> a >> b;
		int res = 0;
		for (int i = 0; i < a.size(); i++) {
			if (a[i] != b[i]) res++;
		}
		cout << "Hamming distance is " << res << ".\n";
	}
}