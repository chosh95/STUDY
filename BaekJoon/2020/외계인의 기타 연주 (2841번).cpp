#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

int N, P;
stack<int> st[7];

int main()
{
	cin >> N >> P;
	int res = 0;
	for (int line, p, i = 0; i < N; i++) {
		cin >> line >> p;
		if (st[line].empty()) {
			st[line].push(p);
			res++;
		}
		else {
			while (!st[line].empty() && st[line].top() > p){
				st[line].pop();
				res++;
			}
			if (!st[line].empty() && st[line].top() == p) {
				continue;
			}
			res++;
			st[line].push(p);
		}
	}

	cout << res;
}