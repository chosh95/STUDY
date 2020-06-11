#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int N, n;

int main()
{
	cin >> N;

	priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
	while (N--) {
		cin >> n;
		if (n == 0) {
			if (q.empty()) {
				cout << "0\n";
				continue;
			}
			cout << q.top().second << "\n";
			q.pop();
		}
		else {
			q.push({ abs(n),n });
		}
	}
}