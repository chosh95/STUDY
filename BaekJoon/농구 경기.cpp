#include <iostream>
#include <string>
using namespace std;
int p[27];
int main()
{
	int T;
	cin >> T;
	while (T--) {
		string str;
		cin >> str;
		p[str[0]-'a']++;
	}
	bool tmp = false;
	for (int i = 0; i <= 26; i++) {
		if (p[i] >= 5) {
			cout << (char)('a' + i);
			tmp = true;
		}
	}
	if (tmp == false) cout << "PREDAJA";
}