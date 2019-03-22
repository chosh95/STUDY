#include <iostream>
using namespace std;
int p[1000][1000];
void paper(int x, int y)
{
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			p[x + i][y + j] = 1;
		}
	}
}
void cal(int len)
{
	long long sum = 0;
	for (int i = 0; i < len+11; i++) {
		for (int j = 0; j < len+11; j++) {
			if (p[i][j] == 1) sum++;
			else continue;
		}
	}
	cout << sum;
}

int main()
{
	int T, a, b, len = 0;
	cin >> T;
	while (T--) {
		cin >> a >> b;
		if (a >= len)len = a;
		if (b >= len) len = b;
		paper(a, b);
	}
	cal(len);
	return 0;
}