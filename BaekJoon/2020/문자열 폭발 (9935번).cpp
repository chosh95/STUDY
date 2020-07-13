#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;
string str;
string bomb;
string ans;

int main()
{
	cin >> str >> bomb;
	int sLen = str.length();
	int bLen = bomb.length();

	for (int i = 0; i < str.size(); i++) {
		ans += str[i];
		if (str[i] == bomb[bLen - 1] && i >= bLen - 1) {
			bool isPossible = true;
			for (int j = 0; j < bLen; j++) {
				if (ans[ans.size() - bLen + j] != bomb[j]) {
					isPossible = false;
					break;
				}
			}
			if (isPossible) {
				for (int j = 0; j < bLen; j++) ans.pop_back();
			}
		}
	}
	if (!ans.empty())
		cout << ans;
	else
		cout << "FRULA";
}