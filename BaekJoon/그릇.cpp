#include <iostream>
#include <string>
using namespace std;
int main()
{
	int res = 0;
	string str;
	cin >> str;
	res = 10;
	for (int i = 1; i < str.size(); i++) {
		if (str[i] == str[i - 1]) res += 5;
		else res += 10;
	}
	cout << res;
}