#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;
int N;
int res;

int main()
{
	cin >> N;
	while (N--) {
		string str;
		cin >> str;
		stack<char> st;
		for (int i = 0; i < str.size(); i++) {
			if (st.empty()) {
				st.push(str[i]);
				continue;
			}
			if (st.top() == str[i]) {
				st.pop();
			}
			else {
				st.push(str[i]);
			}
		}
		if (st.empty())
			res++;
	}
	cout << res;
}