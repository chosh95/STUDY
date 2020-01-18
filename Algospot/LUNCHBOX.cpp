#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int C, N;

int heat(vector<int> m, vector<int> e)
{
	vector<pair<int, int>> order;
	for (int i = 0; i < N; i++)
		order.push_back({ -e[i],i });
	sort(order.begin(), order.end());
	int res = 0, beginEat = 0;
	for (int i = 0; i < N; i++) {
		int idx = order[i].second;
		beginEat += m[idx];
		res = max(res, beginEat - order[i].first);
	}
	return res;
}

int main()
{
	cin >> C;
	while (C--) {
		cin >> N;
		vector<int> m(N);
		vector<int> e(N);
		for (int i = 0; i < N; i++) 
			cin >> m[i];
		for (int i = 0; i < N; i++) 
			cin >> e[i];
		cout << heat(m,e) << endl;
	}
}