#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;
int N;
string origin;
int l, o, v, e;

struct cmp {
	bool operator()(pair<int, string> a, pair<int, string> b) {
		if (a.first == b.first)
			return a.second > b.second;
		return a.first <= b.first;
	}
};

int main()
{
	cin >> origin;
	for (int i = 0; i < origin.size(); i++) {
		if (origin[i] == 'L') l++;
		if (origin[i] == 'O') o++;
		if (origin[i] == 'V') v++;
		if (origin[i] == 'E') e++;
	}

	cin >> N;
	priority_queue<pair<int, string>, vector<pair<int, string>>, cmp> q;
	while (N--) {
		int tmpL = l, tmpO = o, tmpV = v, tmpE = e;
		string str;
		cin >> str;
		for (int i = 0; i < str.size(); i++) {
			if (str[i] == 'L') tmpL++;
			if (str[i] == 'O') tmpO++;
			if (str[i] == 'V') tmpV++;
			if (str[i] == 'E') tmpE++;
		}
		int res = ((tmpL + tmpO) * (tmpL + tmpV) * (tmpL + tmpE) * (tmpO + tmpV) * (tmpO + tmpE) * (tmpV + tmpE)) % 100;
		q.push({ res, str });
	}
	cout << q.top().second;
}