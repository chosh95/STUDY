#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
string str;
bool flag = false;

void JavaToC() {
	while (str.find('_') != string::npos) {
		int pos = str.find('_');
		str.erase(pos,1);
		str[pos] -= ('a' - 'A');
	}
}

void CToJava() {
	for (int i = 0; i < str.size(); i++) {
		if (str[i] < 'a') {
			str.insert(i, "_");
			str[i+1] += ('a' - 'A');
			i++;
		}
	}	
}

int main()
{
	cin >> str;
	//첫 문자가 대문자 또는 _ 또는 마지막 문자가 _면 오류
	if (str[0] < 'a' || str[0]=='_' || str[str.size()-1]=='_') flag = true;
	//연속으로 _가 나오면 오류
	if (flag == false) {
		for (int i = 0; i < str.size()-1; i++) {
			if (str[i] == '_' && str[i + 1] == '_') {
				flag = true;
				break;
			}
		}
	}

	if (str.find('_') != string::npos) {
		//자바 문자에서 대문자가 나오면 오류
		for (int i = 0; i < str.size(); i++) {
			if ('A' <= str[i] && str[i] <= 'Z') {
				flag = true;
				break;
			}
		}
		JavaToC();
	}
	else {
		CToJava();
	}

	if (flag) cout << "Error!";
	else cout << str;
}