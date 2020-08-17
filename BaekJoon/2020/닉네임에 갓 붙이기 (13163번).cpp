#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int N;

int main()
{
	cin >> N;
	cin.ignore();

	while (N--) {
		string str;
		getline(cin, str);
		for (int cnt = 0, i = 0; i < str.size(); i++) {
			if (cnt == 0) {
				if (str[i] == ' ') {
					cout << "god";
					cnt++;
				}
			}
			else {
				if (str[i] != ' ')
					cout << str[i];
			}
		}
		cout << "\n";
	}
}