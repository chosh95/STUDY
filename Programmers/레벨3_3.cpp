#include <string>
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <deque>
#include <vector>

using namespace std;

vector<int> solution(vector<string> operations) {
	vector<int> answer;
	deque<int> dq;
	for (int i = 0; i < operations.size(); i++) {
		string str = operations[i];
		if (str[0] == 'I') {
			int num = stoi(str.substr(2));
			dq.push_back(num);
			sort(dq.begin(), dq.end());
		}
		else {
			if (dq.empty()) continue;
			if (str[2] == '-')
				dq.pop_front();
			else
				dq.pop_back();
		}
	}
	if (dq.empty()) {
		answer.push_back(0);
		answer.push_back(0);
	}
	else {
		answer.push_back(dq.back());
		answer.push_back(dq.front());
	}
	return answer;
}

int main()
{
	vector<int> ans = solution({ "I -45", "I 653", "D 1", "I -642", "I 45", "I 97", "D 1", "D -1", "I 333" });
	cout << ans[0] << " " << ans[1];
}