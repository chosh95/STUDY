#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
vector<int> v[5001];
int N;
int res;
int main()
{
	cin >> N;
	for (int i = 1, a, b; i <= N; i++) {
		cin >> a >> b;
		v[b].push_back(a);
	}
	int tmp;
	for (int i = 1; i <= N; i++) {
		sort(v[i].begin(), v[i].end());
		for (int j = 0; j < v[i].size(); j++) {
			if (j == 0) tmp = v[i][1] - v[i][0];
			else if (j == v[i].size()-1) tmp = v[i][j] - v[i][j - 1];
			else tmp = min(abs(v[i][j] - v[i][j - 1]), abs(v[i][j] - v[i][j + 1]));
			res += tmp;
		}
	}
	cout << res;
}