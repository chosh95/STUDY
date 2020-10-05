#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int N;
vector<string> v;

int main()
{
	cin >> N;
	string s;
	for (int i = 0; i < N; i++) {
		cin >> s;
		v.push_back(s);
	}

	int answer = 0;
	for (int i = 1; i < s.size(); i++) {
		if (answer != 0) break;
		bool p1 = true;

		for (int j = 0; j < v.size(); j++) {
			string cur = v[j].substr(v[j].size() - i, i);
			bool p2 = true;
			for (int k = j+1; k < v.size(); k++) {
				if (v[k].find(cur,v[k].size()-i) != string::npos) {
					p1 = false;
					p2 = false;
					break;
				}
			}
			if (!p2) break;
		}
		
		if (p1)
			answer = i;
	}

	if (answer == 0) answer = s.size();
	cout << answer;
}