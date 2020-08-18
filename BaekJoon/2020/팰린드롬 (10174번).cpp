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
		bool isTrue = true;
		string str;
		getline(cin, str);

		for (int i = 0; i < str.size() / 2; i++) {
			if (str[i] != str[str.size() - 1 - i]) {
				if((('a'<=str[i] && str[i]<='z')&&('A'<=str[str.size()-1-i] && str[str.size()-1-i]<='Z') ||
					('A' <= str[i] && str[i] <= 'Z') && ('a' <= str[str.size() - 1 - i] && str[str.size() - 1 - i] <= 'z'))) continue;
				isTrue = false;
				break;
			}
		}

		if (isTrue) cout << "Yes\n";
		else cout << "No\n";
	}
}