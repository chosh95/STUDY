#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N;
int p[100001];
vector<int> v;

int main()
{
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> p[i];

	for (int i = 1; i <= N; i++) {
		if (v.empty() || v.back() < p[i]) v.push_back(p[i]);
		else {
			auto it = lower_bound(v.begin(), v.end(), p[i]);
			*it = p[i];
		}
	}

	cout << N - v.size();
}