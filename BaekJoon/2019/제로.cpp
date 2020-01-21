#include <iostream>
#include <stack>
using namespace std;

int main()
{
	int N;
	cin >> N;
	int tmp;
	stack<int> s;
	while (N--) {
		cin >> tmp;
		if (tmp != 0) s.push(tmp);
		else s.pop();
	}
	int ans = 0;
	int l = s.size();
	for (int i = 0; i < l; i++) {
		ans += s.top();
		s.pop();
	}
	cout << ans;
}