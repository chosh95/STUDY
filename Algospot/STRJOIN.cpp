#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int C, N;

int sjoin(vector<int> v)
{
	sort(v.begin(), v.end());
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 0; i < N; i++) pq.push(v[i]);
	int res = 0;
	while (pq.size()>1) {
		int minA = pq.top(); pq.pop();
		int minB = pq.top(); pq.pop();
		pq.push(minA + minB);
		res += minA + minB;
	}
	return res;
}

int main()
{
	cin >> C;
	while (C--) {
		cin >> N;
		vector<int> v(N);
		for (int i = 0; i < N; i++) cin >> v[i];
		cout << sjoin(v) << endl;
	}
}