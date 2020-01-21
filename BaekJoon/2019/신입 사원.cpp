#include <iostream>
#include <memory.h>
#include <algorithm>
#include <vector>
using namespace std;
int N;

int main()
{
	int T;
	cin >> T;
	while (T--) {
		cin >> N;
		vector<pair<int, int>> v;
		for (int i = 0, a, b; i < N; i++) {
			cin >> a >> b;
			v.push_back({ a,b });
		}
		sort(v.begin(),v.end());

		int cnt = 1;
		int tmp = v[0].second;
		for (int i = 1; i < N; i++) {
			if (v[i].second < tmp) {
				cnt++;
				tmp = v[i].second;
			}
		}
		cout << cnt<<"\n";
	}
}