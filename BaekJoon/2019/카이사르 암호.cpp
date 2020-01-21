#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		s[i] -= 3;
		if (s[i] < 'A') s[i] += 26;
	}
	cout << s;
}