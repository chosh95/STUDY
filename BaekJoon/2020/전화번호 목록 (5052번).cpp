#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int T, N;

int main()
{
	cin >> T;
	while (T--) {
		cin >> N;
		vector<string> v;
		string tmp;
		for (int i = 0; i < N; i++) {
			cin >> tmp;
			v.push_back(tmp);
		}
		sort(v.begin(), v.end());

		bool isConsistence = true;
		for (int i = 0; i < N - 1; i++) {
			if (v[i].length() > v[i + 1].length())
				continue;
			if (v[i + 1].find(v[i]) == 0) {
				isConsistence = false;
				cout << "NO\n";
				break;
			}
		}
		if (isConsistence)
			cout << "YES\n";
	}
}