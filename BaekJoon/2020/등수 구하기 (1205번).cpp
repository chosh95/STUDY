#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N, score, P;

bool cmp(int a, int b) {
	return a < b;
}

int main()
{
	cin >> N >> score >> P;

	vector<int> v;
	for (int tmp, i = 0; i < N; i++) {
		cin >> tmp;
		v.push_back(tmp);
	}

	int rank = 1;
	if (N == P && v[N - 1] >= score) rank = -1;
	else {
		for (int i = 0; i < N; i++) {
			if (v[i] > score) rank++;
		}
	}
	cout << rank;
}