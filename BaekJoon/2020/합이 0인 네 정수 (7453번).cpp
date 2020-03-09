#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N, p[4][4001];
vector<int> v;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) 
		for (int j = 0; j < 4; j++)
			cin >> p[j][i];

	for (int i = 0; i < N; i++) 
		for (int j = 0; j < N; j++) 
			v.push_back(p[2][i] + p[3][j]);

	sort(v.begin(), v.end());

	long long res = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int target = p[0][i] + p[1][j];
			int lo = lower_bound(v.begin(), v.end(), -target) - v.begin();
			int hi = upper_bound(v.begin(), v.end(), -target) - v.begin();
			if (-target == v[lo])
				res += (hi - lo);
		}
	}
		
	cout << res;
}