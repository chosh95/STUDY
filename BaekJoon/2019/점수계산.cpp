#include <iostream>
using namespace std;
int p[101];
int main()
{
	int N, res = 0, tmp = 0;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> p[i];
		if (p[i] == 0) continue;
		if (p[i - 1] == 0) {
			res += 1;
			tmp = 1;
		}
		else {
			tmp += 1;
			res += tmp;
		}
	}
	cout << res;
}