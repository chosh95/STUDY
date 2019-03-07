#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str;
	cin >> str;
	int cnt = str.size() % 3;
	int idx = 0;
	if (cnt == 1) {
		cout << str[0];
		idx = 1;
	}
	else if (cnt == 2) {
		int num = 0;
		if (str[0] == '1') {
			num += 2;
		}
		if (str[1] == '1') {
			num += 1;
		}
		cout << num;
		idx = 2;
	}
	while (idx<str.size()) {
		int num = 0;
		if (str[idx] == '1') 
			num += 4;
		if (str[idx + 1] == '1') 
			num += 2;		
		if (str[idx + 2] == '1') 
			num += 1;
		cout << num;
		idx += 3;
	}
	return 0;
}