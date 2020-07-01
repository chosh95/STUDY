#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
int N;
vector<int> v;
map<int, int> m;
int main()
{
	cin >> N;
	vector<int> v2;
	for (int tmp, i = 0; i < N; i++) {
		cin >> tmp;
		v.push_back(tmp);
	}

	v2 = v;
	sort(v2.begin(), v2.end());
	int idx = 1;
	for (int i = 0; i < N; i++) {
		if (m[v2[i]] == 0)
			m[v2[i]] = idx++;
		else continue;
	}

	for (int i = 0; i < N; i++) {
		cout << m[v[i]] - 1 << " ";
	}
}