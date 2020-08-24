#include <iostream>
#include <cstring>
#include <algorithm>
#include <map>
#include <string>
using namespace std;
map<string, double> m;

int main()
{
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	string str;
	double cnt = 0;
	while (getline(cin, str)) {
		m[str]++;
		cnt++;
	}

	cout << fixed;
	cout.precision(4);
	for (auto iter = m.begin(); iter != m.end(); iter++) {
		string ans = iter->first;
		double res = iter->second;
		cout << ans << " " << (res / cnt) * 100.0 << "\n";
	}
}