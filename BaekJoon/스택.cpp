#include <iostream>
#include <string>
#include <stack>
using namespace std;
int main()
{
	string c;
	cin >> c;
	stack<char> s;
	int res = 0;
	for (int i = 0; i < c.length(); i++) {
		if (c[i] == '(') s.push('(');
		else if(c[i-1]=='('){
			s.pop();
			res += s.size();
		}
		else {
			s.pop();
			res++;
		}
	}
	cout << res;
}