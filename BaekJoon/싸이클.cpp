#include <iostream>
#include <vector>
using namespace std;
int N, P;
vector<int> v;

int main()
{
	cin >> N >> P;
	v.push_back(N);
	int cur = N;
	while (true) {
		cur *= N;
		cur %= P;
		for (int i = 0; i < v.size(); i++) {
			if (v[i] == cur) {
				cout << v.size() - i;
				return 0;
			}
		}
		v.push_back(cur);
	}
}