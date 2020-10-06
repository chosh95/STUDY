#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int N;
string origin;
string beforeStar, afterStar;

int main()
{
	cin >> N;
	cin >> origin;

	beforeStar = origin.substr(0,origin.find('*'));
	afterStar = origin.substr(origin.find('*')+1);

	for (int i = 0; i < N; i++) {
		string cur;
		cin >> cur;
		bool isPossible = true;
		if (origin.size() - 1 > cur.size()) isPossible = false;

		for (int i = 0; i < beforeStar.size(); i++) {
			if (!isPossible) break;
			if (cur[i] != beforeStar[i]) {
				isPossible = false;
				break;
			}
		}

		for (int j = 0; j < origin.size() - beforeStar.size() - 1; j++) {
			if (!isPossible) break;
			if (cur[cur.size() - 1 - j] != afterStar[afterStar.size() - 1 - j]) {
				isPossible = false;
				break;
			}
		}

		if (isPossible)
			cout << "DA\n";
		else
			cout << "NE\n";
	}
}