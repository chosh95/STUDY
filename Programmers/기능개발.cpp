#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;
	vector<int> day;
	stack<int> st;

	for (int i = 0; i < progresses.size(); i++) {
		int rest = 100 - progresses[i];
		int speed = rest / speeds[i];
		if (rest % speeds[i] != 0) speed++;
		day.push_back(speed);
	}
	for (int i = 0; i < day.size(); i++) {
		if (st.empty()) {
			st.push(day[i]);
			continue;
		}
		if (st.top() < day[i]) {
			answer.push_back(st.size());
			while (!st.empty()) st.pop();
			st.push(day[i]);
		}
		else {
			st.push(st.top());
		}
	}

	if (!st.empty())
		answer.push_back(st.size());

	return answer;
}

int main()
{
	vector<int> res = solution({40,93,30,55,40 }, { 3,1,30,5,4 });
	for (int i = 0; i < res.size(); i++)
		cout << res[i] << " ";
}