#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;
int N;
string origin, lover;
int l, o, v, e;
int cur, res = -1;
int main()
{
	cin >> origin;
	for (int i = 0; i < origin.size(); i++) {
		if (origin[i] == 'L') l++;
		else if (origin[i] == 'O') o++;
		else if (origin[i] == 'V') v++;
		else if (origin[i] == 'E') e++;
	}

	cin >> N;
	while (N--) {
		int tmpL = l, tmpO = o, tmpV = v, tmpE = e;
		string str;
		cin >> str;
		for (int i = 0; i < str.size(); i++) {
			if (str[i] == 'L') tmpL++;
			else if (str[i] == 'O') tmpO++;
			else if (str[i] == 'V') tmpV++;
			else if (str[i] == 'E') tmpE++;
		}
		cur = ((tmpL + tmpO) * (tmpL + tmpV) * (tmpL + tmpE) * (tmpO + tmpV) * (tmpO + tmpE) * (tmpV + tmpE)) % 100;
		if (cur > res) {
			res = cur;
			lover = str;
		}
		else if (cur == res) {
			if (str < lover) lover = str;
		}
	}
	cout << lover;	
}