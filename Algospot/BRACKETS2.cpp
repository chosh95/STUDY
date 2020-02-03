#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

int C;
string match(string str) {
	stack<int> st;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '(') st.push(1);
		else if (str[i] == '{') st.push(2);
		else if (str[i] == '[') st.push(3);
		else if (str[i] == ')') {
			if (st.empty()) return "NO";
			if (st.top() == 1) st.pop();
		}
		else if (str[i] == '}') {
			if (st.empty()) return "NO";
			if (st.top() == 2) st.pop();
		}
		else if (str[i] == ']') {
			if (st.empty()) return "NO";
			if (st.top() == 3) st.pop();
		}
	}
	if (st.empty())
		return "YES";
	else
		return "NO";
}

int main()
{
	cin >> C;
	while (C--) {
		string str;
		cin >> str;
		cout<<match(str)<<endl;
	}
}