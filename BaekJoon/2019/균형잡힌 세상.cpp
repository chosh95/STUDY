#include <iostream>
#include <string>
#include <stack>
using namespace std;

void balance(string s)
{
	stack<char> st;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(') st.push('(');
		else if (s[i] == '[') st.push('[');
		else if (s[i] == ')') {
			if (!st.empty() && st.top() == '(') st.pop();
			else {
				cout << "no\n";
				return;
			}
		}
		else if (s[i] == ']') {
			if (!st.empty() && st.top() == '[') st.pop();
			else {
				cout << "no\n";
				return;
			}
		}
	}
	if(st.empty())	cout << "yes\n";
	else cout << "no\n";
}

int main()
{
	string str;
	while (true) {
		getline(cin, str); //공백 포함 한 줄 입력시
		if (str == ".") return 0;
		else balance(str);
	}
}