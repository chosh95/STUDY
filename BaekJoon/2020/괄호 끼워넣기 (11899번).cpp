#include <iostream>
#include <stack>
#include <string>
using namespace std;
string str;
stack<char> st;

int main()
{
	cin >> str;
	int res = 0;

	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '(') {
			st.push('(');
		}
		else {
			if (st.empty()) {
				res++;
			}
			else {
				st.pop();
			}
		}
	}
	res += st.size();
	cout << res;
}
