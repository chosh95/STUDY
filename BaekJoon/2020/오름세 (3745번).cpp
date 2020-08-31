#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
int N;
vector<int> lis;

int main()
{
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

	while (cin>>N) {
		lis.clear();
		for (int cur, i = 1; i <= N; i++) {
			cin >> cur;
			if (lis.empty() || lis.back() < cur) lis.push_back(cur);
			else {
				int idx = lower_bound(lis.begin(), lis.end(), cur) - lis.begin();
				lis[idx] = cur;
			}
		}
		cout << lis.size() << "\n";
	}
}