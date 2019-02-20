#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s;
	cin >> s;
	char res[101];
	char c[101];
	int j = 1;
	res[0] = s[0];
	for (int i = 1; i < s.length(); i++) {
		c[i] = s[i];
		if (c[i - 1] == '-') res[j++] = c[i];
	}
	for (int i = 0; i <= j - 1; i++) cout << res[i];
}