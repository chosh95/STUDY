#include <iostream>
#include <algorithm>
using namespace std;
int N;
int p[10001];

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> p[i];
	}
	if (prev_permutation(p, p + N) == true) {
		for (int i = 0; i < N; i++) {
			cout << p[i] << " ";
		}
	}
	else cout << "-1";
}