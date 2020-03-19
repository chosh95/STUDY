#include <iostream>
#include <algorithm>
using namespace std;
int N, res;
int p[17];

bool isTrue(int x, int y) {
	for (int i = 1; i < x; i++) {
		if (p[i] == y) return false;
		if (abs(y-p[i]) == x-i) return false;
	}
	return true;
}

void queen(int x, int y) {
	p[x] = y;

	if (x == N) {
		res++;
		p[x] = 0;
		return;
	}

	for (int i = 1; i <= N; i++) {
		if (isTrue(x + 1, i)) {
			queen(x + 1, i);
		}
	}

	p[x] = 0;
}

int main()
{
	cin >> N;
	for (int i = 1; i <= N; i++) 
		queen(1, i);

	cout << res;
}