#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N;
vector<int> v;
vector<int> ans;

int main()
{
	cin >> N;
	for (int tmp, i = 0; i < N; i++) {
		cin >> tmp;
		v.push_back(tmp);
	}

	ans.push_back(v[0]);
	for (int j = 1; j < N; j++) {
		if (ans.back() < v[j])
			ans.push_back(v[j]);
		else {
			auto iter = lower_bound(ans.begin(), ans.end(), v[j]);
			*iter = v[j];
		}
	}

	cout << ans.size() << "\n";
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << " ";
}