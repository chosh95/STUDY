#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
string str;

int main()
{
	cin >> str;
	int num1 = 0, num2 = 0;
	for (int i = 0; i < str.size(); i++) {
		if (i < str.size() / 2) {
			num1 += str[i] - '0';
		}
		else {
			num2 += str[i] - '0';
		}
	}

	if (num1 == num2) cout << "LUCKY";
	else cout << "READY";
}