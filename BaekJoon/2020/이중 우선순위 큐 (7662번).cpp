#include <iostream>
#include <map>
#include <queue>
using namespace std;
int T, Q;
typedef long long ll;
int main()
{
	cin >> T;
	while (T--) {
		cin >> Q;
		priority_queue<ll, vector<ll>, greater<ll>> minQ;
		priority_queue<ll, vector<ll>, less<ll>> maxQ;
		map<ll, ll> m;
		char op;
		ll num;
		while (Q--) {
			cin >> op >> num;
			if (op == 'I') {
				maxQ.push(num);
				minQ.push(num);
				m[num]++;
			}
			else if (num == 1) {
				while (!maxQ.empty() && m[maxQ.top()] == 0) 
					maxQ.pop();
				
				if (!maxQ.empty()) {
					m[maxQ.top()]--;
					maxQ.pop();
				}
			}
			else {
				while (!minQ.empty() && m[minQ.top()] == 0) 
					minQ.pop();
				
				if (!minQ.empty()) {
					m[minQ.top()]--;
					minQ.pop();
				}
			}
		}
		while (!maxQ.empty() && m[maxQ.top()] == 0)
			maxQ.pop();
		while (!minQ.empty() && m[minQ.top()] == 0)
			minQ.pop();
		if (minQ.empty())
			cout << "EMPTY\n";
		else
			cout << maxQ.top() << " " << minQ.top() << "\n";
	}
}