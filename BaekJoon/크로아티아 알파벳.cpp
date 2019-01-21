#include <iostream>
#include <string>
using namespace std;
int main()
{
	string s;
	cin >> s;
	int count=0;
	for (int i = 0; i < s.length(); i++) {
		count++;
		if (s[i] == '=') {
			if (s[i - 1] == 'c' || s[i - 1] == 's') count--;
			else if (s[i - 1] == 'z' && s[i - 2] == 'd') count -= 2;
			else if (s[i - 1] == 'z') count--;
		}
		else if (s[i] == '-') {
			if (s[i - 1] == 'c' || s[i - 1] == 'd') count--;
		}
		else if (s[i] == 'j') {
			if (s[i - 1] == 'l' || s[i - 1] == 'n') count--;
		}
		else if (s[i] == '-') {
			if (s[i - 1] == 'c' || s[i - 1] == 'd') count--;
		}
	}
	cout << count;

}