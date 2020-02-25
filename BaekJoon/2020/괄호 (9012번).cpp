#include <iostream>
#include <stack>
#include <string>
using namespace std;
int C;

int main()
{
	cin >> C;
	while (C--) {
		stack<char> st;
		string input;
		cin >> input;
		bool res = true;
		for (int i = 0; i < input.size(); i++) {
			if (input[i] == '(') 
				st.push('(');
			else if(input[i]==')'){
				if (st.empty()) {
					res = false;
					break;
				}
				else if (st.top() == '(')
					st.pop();
			}
		}
		if (!st.empty()) res = false;
		if (res) cout << "YES\n";
		else cout << "NO\n";
	}
}