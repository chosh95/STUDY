#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
using namespace std;
priority_queue<int> q;

int main()
{
	int N;
	cin >> N;
	int x;
	while (N--) {
		scanf("%d", &x);
		if (x != 0) q.push(-x);
		else {
			if (q.empty()) {
				cout << "0\n";
			}
			else {
				cout << q.top()*(-1) << "\n";
				q.pop();
			}
		}
	}
}