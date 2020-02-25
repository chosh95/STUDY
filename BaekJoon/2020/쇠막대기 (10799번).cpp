#include <iostream>
#include <string>
#include <stack>
using namespace std;
string str;
stack<int> st;

int main()
{
	cin >> str;
	int cnt = 0;
	int sum = 0;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '(') 
			st.push(cnt++);
		else {
			cnt--;
			if (str[i - 1] == '(')
				sum += cnt;
			else
				sum++;
			st.pop();
		}
	}
	cout << sum;
}