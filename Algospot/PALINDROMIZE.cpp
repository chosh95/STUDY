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

int maxOverlap(const string & str, const string & strReverse) {
	vector<int> pi = getPi(strReverse);
	int n = str.length(), j = 0;
	for (int i = 0; i < n; i++) {
		while (j > 0 && str[i] != strReverse[j])
			j = pi[j - 1];
		if (str[i] == strReverse[j]) {
			if (j == n - 1) return n;
			else j++;
		}
	}
	return j;
}

int main()
{
	cin >> C;
	while (C--) {
		string str, strReverse;
		cin >> str;
		for (int i = str.size() - 1; i >= 0; i--)
			strReverse += str[i];
		cout << str.length() * 2 - maxOverlap(str, strReverse) << endl;
	}
}