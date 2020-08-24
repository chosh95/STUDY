#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int N;

int main()
{
	while (true) {
		cin >> N;
		if (N == 0) break;
		cin.ignore();

		string str;
		int idx = 0;
		while (N--) {
			getline(cin, str);
			for (int i = idx; i < str.size(); i++) {
				if (str[i] == ' ') {
					idx = i;
					break;
				}
				else if (i == str.size() - 1) {
					idx = str.size();
					break;
				}
			}
		}
		cout << idx + 1 << "\n";
	}
}