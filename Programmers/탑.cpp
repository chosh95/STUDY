#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// heights_len은 배열 heights의 길이입니다.
vector<int> solution(vector<int> p) {
	vector<int> answer(p.size());
	stack<pair<int, int>> st;
	for (int i = 0; i < p.size(); i++) {
		if (st.empty()) {
			answer[i] = 0;
			st.push({ p[i],i+1 });
		}
		else if (st.top().first > p[i]) {
			answer[i] = st.top().second;
			st.push({ p[i],i+1 });
		}
		else if (st.top().first <= p[i]) {
			while (!st.empty() && st.top().first <= p[i]) {
				st.pop();
			}			
			if (st.empty()) {
				answer[i] = 0;
				st.push({ p[i],i+1 });
			}
			else if (st.top().first > p[i]) {
				answer[i] = st.top().second;
				st.push({ p[i],i+1 });
			}
		}
	}
	return answer;
}

int main()
{
	vector<int> v = { 1,5,3,6,7,6,5 };
	vector<int> res = solution(v);

	for (int i = 0; i < res.size(); i++)
		cout << res[i] << " ";
}