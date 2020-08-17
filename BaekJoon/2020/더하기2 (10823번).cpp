#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	string str;
	string cur;
	int res = 0;
	while (getline(cin, str)) {
		for (int i = 0; i < str.size(); i++) {
			if (str[i] != ',') cur += str[i];
			else {
				res += stoi(cur);
				cur = "";
			}
		}
	}
	res += stoi(cur);
	cout << res;
}