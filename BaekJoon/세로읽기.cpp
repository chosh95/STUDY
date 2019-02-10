#include <iostream>
#include <string>
using namespace std;

int main()
{
	int p[5];
	char s[5][15];
	string S;
	for (int i = 0; i <= 4; i++) {
		cin >> S;
		p[i] = S.length();
		for (int j = 0; j < S.length(); j++) {
			s[i][j] = S[j];
		}
	}
	for (int j = 0; j <= 14; j++) {
		for (int i = 0; i <= 4; i++) {
			if (p[i]>j) cout << s[i][j];
			else continue;
		}
	}
}