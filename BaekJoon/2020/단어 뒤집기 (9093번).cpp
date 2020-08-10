#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int N;

int main()
{
	cin >> N;
	cin.ignore();
	string s;
	while (N--) {
		int start = 0;
		int end = 0;
		getline(cin,s);

		for (int i = 0; i <= s.length(); i++) {
			if (s[i] == ' ' || i == s.length()) {
				string tmp = s.substr(start, end);
				reverse(tmp.begin(), tmp.end());
				cout << tmp << " ";
				start = i+1;
				end = -1;
			}
			end++;
		}
		cout << "\n";
	}
	
}