#include <iostream>
#include <map>
using namespace std;
int N;

int main()
{
	cin >> N;
	map<long long, int> m;
	long long tmp;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		m[tmp]++;
	}
	int maxNum = 0;
	long long res;
	for (auto n : m) {
		if (maxNum < n.second) {
			maxNum = n.second;
			res = n.first;
		}
	}
	cout << res;
}
