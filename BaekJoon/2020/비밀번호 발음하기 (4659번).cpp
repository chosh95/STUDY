#include <iostream>
#include <set>
#include <string>
using namespace std;

int main() {
	set<char> s;
	s.insert('a');
	s.insert('e');
	s.insert('i');
	s.insert('o');
	s.insert('u');

	while (true) {
		string str;
		cin >> str;
		if (str == "end") break;

		int vow = 0;
		int cnt1 = 0 , cnt2 = 0;
		bool isPossible = true;
		for (int i = 0; i < str.size(); i++) {
			if (s.find(str[i]) != s.end()) {
				vow++;
				cnt1++;
				cnt2 = 0;
				if (cnt1 == 3) {
					isPossible = false;
					break;
				}
			}
			else {
				cnt2++;
				cnt1 = 0;
				if (cnt2 == 3) {
					isPossible = false;
					break;
				}
			}
			if (i < str.size() - 1 && str[i] == str[i + 1] && str[i] != 'e' && str[i] != 'o') {
				isPossible = false;
				break;
			}
		}
		if (vow == 0) isPossible = false;

		if (isPossible)
			cout << "<" << str << "> is acceptable.\n";
		else
			cout << "<" << str << "> is not acceptable.\n";
	}
}