#include <iostream>
using namespace std;
int p[101][101];

int main()
{
	int a, b, c, d;
	for (int i = 1; i <= 4; i++) {
		cin >> a >> b >> c >> d;
		for (int j = a; j < c; j++) {
			for (int k = b; k < d; k++) {
				p[j][k] = 1;
			}				
		}
	}
	int res = 0;
	for (int i = 1; i <= 100; i++) {
		for (int j = 1; j <= 100; j++) {
			if (p[i][j] == 1)res++;
		}
	}
	cout << res;
}