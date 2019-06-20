#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int N;

int main()
{
	cin >> N;
	vector<int> p;
	int tmp;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		p.push_back(tmp);
	}
	if (next_permutation(p.begin(), p.end())) {
		for (int i = 0; i < N; i++) {
			cout << p[i] << " ";
		}
	}
	else cout << -1;
}