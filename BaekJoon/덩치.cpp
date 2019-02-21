#include <iostream>
#include <algorithm>
using namespace std;
int p[51][2];
int res[51];
int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> p[i][0] >> p[i][1];
		res[i] = 1;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == j) continue;
			if (p[i][0] < p[j][0] && p[i][1] < p[j][1]) {
				res[i]++;
			}
		}
	}
	for (int i = 0; i < N; i++) cout << res[i] << " ";
}
