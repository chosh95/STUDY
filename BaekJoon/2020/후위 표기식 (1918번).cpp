#include <iostream>
#include <string>
#include <stack>
using namespace std;
string str;

int main()
{
	cin >> str;	
	stack<char> s;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] >= 'A' && str[i] <= 'Z') 
			cout << str[i];
		else if (str[i] == '(')
			s.push('(');
		else if (str[i] == ')') {
			while (!s.empty() && s.top() != '(') {
				cout << s.top();
				s.pop();
			}
			s.pop();
		}
		else if (str[i] == '*' || str[i] == '/') {
			while (!s.empty() && (s.top() == '*' || s.top() == '/')) {
				cout << s.top();
				s.pop();
			}
			s.push(str[i]);
		}
		else if(str[i]=='+' || str[i]=='-'){
			while (!s.empty() && s.top() != '(') {
				cout << s.top();
				s.pop();
			}
			s.push(str[i]);
		}
	}
	while (!s.empty()) {
		cout << s.top();
		s.pop();
	}
	return 0;
}
