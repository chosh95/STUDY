#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	string a, b;
	cin >> a >> b;
	int la = a.size();
	int lb = b.size();
	int res = 99;
	for (int i = 0; i <= lb - la; i++) {
		int tmp = 0;
		for (int j = 0; j < la; j++) {
			if (a[j] == b[j + i]) continue;
			else tmp++;
		}
		res = min(res, tmp);
	}
	cout << res;
}