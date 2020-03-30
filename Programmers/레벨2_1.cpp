#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;

map<string, int> m;
vector<int> solution(int n, vector<string> words) {
	vector<int> answer;
	int idx = 1;
	int circle = 1;
	for (int i = 0; i < words.size(); i++) {
		if ((i != 0 && words[i - 1][words[i - 1].size()-1] != words[i][0]) || m[words[i]] != 0) {
			answer.push_back(idx);
			answer.push_back(circle);
			break;
		}
		else {
			m[words[i]]++;
			idx += 1;
			if (idx > n) {
				idx = 1;
				circle++;
			}
		}
	}
	if (answer.empty()) {
		answer.push_back(0);
		answer.push_back(0);
	}
	return answer;
}

int main()
{
	vector<string> tmp = { "tank", "kick", "know", "wheel", "land", "dream", "mother", "robot", "tank" };
	vector<int> res = solution(3, tmp);
	cout << res[0] << " " << res[1];
}

