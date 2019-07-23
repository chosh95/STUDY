#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N;
bool p[2002];
vector<int> v;
int main()
{
	cin >> N;
	for (int i = 1, a; i <= N; i++) {
		cin >> a;
		if (a < 0) {
			int tmp = a + 2001;
			if (p[tmp]) continue;
			p[tmp] = true;
			v.push_back(a);
		}
		else {
			if (p[a] == true) continue;
			p[a] = true;
			v.push_back(a);
		}
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
}