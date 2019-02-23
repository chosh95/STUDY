#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
	string str;
	stack<char> s;
	int sum = 0, mul = 1;
	cin >> str;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '('){
			mul *= 2;
			s.push('(');
		}
		else if (str[i] == '[') {
			mul *= 3;
			s.push('[');
		}
		else if (str[i] == ')') {
			if (s.empty()) {
				cout << 0;
				return 0;
			}
			if (str[i - 1] == '(') sum += mul;
			if (s.top() == '(') s.pop();
			mul /= 2;
		}		
		else if (str[i] == ']') {
			if (s.empty()) {
				cout << 0;
				return 0;
			}
			if (str[i - 1] == '[')	sum += mul;
			if (s.top() == '[') s.pop();
			mul /= 3;
		}
	}
	if (!s.empty()) cout << 0;
	else cout << sum;
}
