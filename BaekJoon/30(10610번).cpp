#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	string s;
	cin >> s;
	int sum = 0;
	for (int i = 0; i < s.size(); i++) {
		sum += s[i] - '0';
	}
	sort(s.begin(), s.end());

	if (sum % 3 != 0 || s[0]!='0') {
		cout << -1;
		return 0;
	}
	for (int i = s.size() - 1; i >= 0; i--)
		cout << s[i];
}