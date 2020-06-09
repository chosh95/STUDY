#include <string>
#include <algorithm>
#include <vector>
#include <iostream>
#include <map>
using namespace std;

vector<int> solution(string s) {
	vector<int> answer;
	vector<pair<int,vector<int>>> v;
	vector<int> tmp;
	map<int, int> m;
	for (int t=0, i = 0; i < s.size()-1; i++) {
		if (s[i] == '{') continue;
		else if (s[i] == '}') {
			tmp.push_back(t);
			t = 0;
			v.push_back({ tmp.size(),tmp });
			tmp.clear();
		}
		else if (s[i] == ',') {
			if (s[i - 1] == '}') continue;
			tmp.push_back(t);
			t = 0;
		}
		else {
			t *= 10;
			t += (s[i] - '0');
		}
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v[i].second.size(); j++) {
			int cur = v[i].second[j];
			if (m[cur] == 0) {
				m[cur] = 1;
				answer.push_back(cur);
			}
		}
	}
	return answer;
}

int main()
{
	vector<int> ans = solution("{{2},{2,1},{2,1,3},{2,1,3,4}}");
}