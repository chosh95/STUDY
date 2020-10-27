#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, A, B, C;
vector<int> v;

int main()
{
	cin >> N >> A >> B >> C;
	for (int t, i = 0; i < N; i++) {
		cin >> t;
		v.push_back(t);
	}
	sort(v.begin(), v.end());

	int res = C / A, cost = A, cal = C;
	
	for (int i = v.size() - 1; i >= 0; i--) {
		int curCal = cal + v[i]; 
		int curCost = cost + B;
		if (res > curCal / curCost) break;
		cost = curCost;
		cal = curCal;
		res = curCal / curCost;
	}
	cout << res;
}