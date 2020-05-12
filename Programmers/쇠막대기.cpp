#include <string>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int solution(string str) {
	int answer = 0;
	stack<int> st;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '(') st.push(1);
		else {
			st.pop();
			if (str[i - 1] == '(') 
				answer += st.size();
			else
				answer++;
		}
	}
	return answer;
}

int main()
{
	cout << solution("()(((()())(())()))(())") << endl;
}