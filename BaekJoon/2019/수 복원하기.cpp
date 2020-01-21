#include <iostream>
#include <memory.h>
#include <vector>
using namespace std;
int N;
void cal(int t)
{
	vector<pair<int, int>> v;
	for (int i = 2; i <= t; i++) {
		int cnt = 0;
		while (t%i == 0) {
			t /= i;
			cnt++;
		}
		if (cnt != 0) v.push_back({ i,cnt });
	}
	if (t != 1) v.push_back({ N,1 });

	for (int i = 0; i < v.size(); i++) {
		cout << v[i].first << " " << v[i].second << "\n";
	}
}

int main()
{
	int T;
	cin >> T;
	while (T--) {
		cin >> N;
		cal(N);
	}
	return 0;
}