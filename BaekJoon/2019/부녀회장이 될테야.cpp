#include <iostream>
using namespace std;
int p[15][15];
int main()
{
	int T;
	cin >> T;
	for (int i = 0; i <= 14; i++) {
		p[0][i] = i;
		p[i][1] = 1;
	}
	for (int i = 1; i <= 14; i++) {
		for (int j = 2; j <= 14; j++) {
			p[i][j] = p[i - 1][j] + p[i][j - 1];
		}
	}
	for (int i = 1; i <= T; i++) {
		int k, n;
		cin >> k >> n;
		cout << p[k][n] << endl;
	}
}