#include <iostream>
#include <math.h>
#include <memory.h>
using namespace std;
int N, M;
int cur = 100, cnt = 9999999;
bool p[11];

int possible(int a)
{
	if (a == 0) {
		if (p[a] == false) return -1;
		else return 1;
	}
	int len = 0;
	while (a>0) {
		if (p[a % 10] == false) return -1;
		else {
			len++;
			a /= 10;
		}
	}
	return len;
}

int main()
{
	cin >> N >> M;
	int tmp;
	memset(p, true, sizeof(p));

	for (int i = 1; i <= M; i++) {
		cin >> tmp;
		p[tmp] = false;
	}
	cnt = abs(100 - N);
	for (int i = 0; i <= 1000000; i++) {
		int tmp = possible(i);
		if (tmp != -1) {
			int len = tmp + abs(i - N);
			if (cnt > len) cnt = len;
		}
	}
	cout << cnt;
}