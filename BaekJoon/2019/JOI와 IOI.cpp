#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s;
	cin >> s;
	int cnt1 = 0, cnt2 = 0;
	for (int i = 0; i < s.size() - 1; i++) {
		if (s[i] == 'J') {
			if (s[i + 1] == 'O' && s[i + 2] == 'I') cnt1++;
		}
		if (s[i] == 'I') {
			if (s[i + 1] == 'O' && s[i + 2] == 'I') cnt2++;
		}
	}
	cout << cnt1 << endl << cnt2;
}