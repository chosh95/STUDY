#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N;
vector<pair<int, int>> v;

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		v.push_back({ a,b });
	}
	sort(v.begin(),v.end());
	
	int res = 0, l = -1000000000, r = -1000000000;
	for (int i = 0; i < N; i++) {
		if (r < v[i].first) {
			res += r - l;
			r = v[i].second;
			l = v[i].first;
		}
		else r = max(r, v[i].second);
	}
	res += r - l;
	cout << res;
}