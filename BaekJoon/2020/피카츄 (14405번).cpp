#include <iostream>
#include <string>
using namespace std;
string str;

int main()
{
	cin >> str;
	bool isTrue = true;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == 'p') {
			if (str[i + 1] == 'i') i++;
			else {
				isTrue = false;
				break;
			}
		}
		else if (str[i] == 'k') {
			if (str[i + 1] == 'a') i++;
			else {
				isTrue = false;
				break;
			}
		}
		else if (str[i] == 'c') {
			if (str[i + 1] == 'h' && str[i + 2] == 'u') i += 2;
			else {
				isTrue = false;
				break;
			}
		}
		else {
			isTrue = false;
			break;
		}
	}

	if (isTrue) cout << "YES";
	else cout << "NO";
}