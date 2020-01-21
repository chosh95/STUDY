#include <iostream>
#include <stack>
using namespace std;
int N;
int p[500001];
int main()
{
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> p[i];
	stack<pair<int,int>> s;
	s.push({ 1,p[1] });
	cout << "0 ";
	for (int i = 2; i <= N; i++) {
		while (!s.empty()) {
			if (p[i] > s.top().second) {
				s.pop();
			}
			else {
				cout << s.top().first << " ";
				break;
			}
		}
		if (s.empty()) cout << "0 ";
		s.push({ i,p[i] });
	}
	return 0;
}