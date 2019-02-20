#include <iostream>
using namespace std;
int p[6][5];
int main()
{
	int maxnum = 0, maxidx = 0;
	for (int i = 1; i <= 5; i++) {
		for (int j = 1; j <= 4; j++) {
			cin >> p[i][j];
			p[i][0] += p[i][j];
		}
		if (p[i][0] > maxnum) {
			maxnum = p[i][0];
			maxidx = i;
		}
	}
	cout << maxidx << " " << maxnum;
}