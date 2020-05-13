#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <string>
#include <deque>
#include <vector>

using namespace std;

vector<int> solution(vector<string> operations) {
	vector<int> answer;
	deque<int> dq;
	for (int i = 0; i < operations.size(); i++) {
		string str = operations[i];
		char oper = str[0];
		int num = stoi(str.substr(2));
		if (oper == 'I') {
			dq.push_back(num);
			sort(dq.begin(), dq.end());
		}
		else {
			if (dq.empty()) continue;
			if (num == 1) dq.pop_back();
			else if (num == -1) dq.pop_front();
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
	vector<int> ans = solution({ "I 16", "I -5643", "D -1", "D 1", "D 1", "I 123", "D -1" });
	cout << ans[0] << " " << ans[1] << endl;
}