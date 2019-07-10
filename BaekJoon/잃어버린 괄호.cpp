#include <iostream>
#include <string>
using namespace std;
int p[50];
char c[50];
int main()
{
	string s;
	cin >> s;
	string tmp = "";
	int j = 0, k = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] != '-' && s[i] != '+') {
			tmp += s[i];
		}
		else {
			p[j++] = stoi(tmp);
			c[k++] = s[i];
			tmp = "";
		}
	}
	p[j] = stoi(tmp);

	int res = 0;
	bool minus = false;
	for (int i = 0; i <= j; i++) {
		if (!minus) res += p[i];
		else res -= p[i];
		if (c[i] == '-') minus = true;
	}

	cout << res;
}