#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> v;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	v.resize(N * N + 1);
	for (int i = 0; i < N * N; i++)
		cin >> v[i];
	
	sort(v.begin(), v.end());
	cout << v[N * N - N + 1];
}