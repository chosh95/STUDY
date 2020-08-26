#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int res;
int N;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	priority_queue<int, vector<int>, greater<int>> q;
	for (int tmp, i = 1; i <= N; i++) {
		cin >> tmp;
		q.push(tmp);
	}

	while (q.size() != 1) {
		int x = q.top();
		q.pop();
		int y = q.top();
		q.pop();
		res += (x + y);
		q.push(x + y);
	}

	cout << res;
}