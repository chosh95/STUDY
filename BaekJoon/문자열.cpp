#include <iostream>
#include <string>
using namespace std;

int main()
{
	int T;
	string s;
	char a, b;
	cin >> T;
	while (T--) {
		cin >> s;
		a = s[0];
		b = s[s.size()-1];
		cout << a << b << "\n";
	}
}