#include <iostream>
#include <cstring>
#include <vector>
#include <string>
using namespace std;
int C;

vector<int> getPi(const string& str) {
	int m = str.size(), j = 0;
	vector<int> pi(m, 0);
	for (int i = 1; i < m; i++) {
		while (j > 0 && str[i] != str[j])
			j = pi[j - 1];
		if (str[i] == str[j])
			pi[i] = ++j;
	}
	return pi;
}

int maxOverlap(const string &str, const string& strReverse) {
	vector<int> pi = getPi(strReverse);
	int n = str.size(), m = strReverse.size();
	int i = 0, j = 0;
	while (i < n) {
		if (j < m && str[i + j] == strReverse[j]) {
			++j;
			if (i + j == n) return j;
		}
		else {
			if (j == 0) ++i;
			else {
				i += j - pi[j - 1];
				j = pi[j-1];
			}
		}
	}
}

int main()
{
	cin >> C;
	while (C--) {
		string str, strReverse;
		cin >> str;
		for (int i = str.size() - 1; i >= 0; i--)
			strReverse += str[i];
		cout << str.length() * 2 - maxOverlap(str,strReverse) << endl;
	}
}