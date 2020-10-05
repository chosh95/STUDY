#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
string str;
int p[27];

int main()
{
	cin >> str;
	for (int i = 0; i < str.size(); i++) 
		p[str[i] - 'A']++;
	
	int oddCnt = 0, oddIdx = 0;
	for (int i = 0; i < 26; i++) 
		if (p[i] % 2 == 1) {
			oddCnt++;
			oddIdx = i;
		}
			

	if (oddCnt > 1) 
		cout << "I'm Sorry Hansoo";
	else {
		for (int i = 0; i < 26; i++) {
			for (int j = 0; j < p[i] / 2; j++) {
				cout << (char)(i + 'A');
			}
		}

		if (oddCnt == 1) {
			cout << (char)(oddIdx + 'A');
		}

		for (int i = 25; i >=0; i--) {
			for (int j = 0; j < p[i] / 2; j++) {
				cout << (char)(i + 'A');
			}
		}
	}
}