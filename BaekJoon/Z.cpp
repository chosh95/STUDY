#include <iostream>
#include <math.h>
using namespace std;

int N, s, cnt, r, c;
void move(int size, int x, int y)
{
	if (size == 2) {
		if (x == r && y == c) {
			cout << cnt;
			return;
		}
		++cnt;
		if (x == r && y + 1 == c) {
			cout << cnt;
			return;
		}
		++cnt;
		if (x + 1 == r && y == c) {
			cout << cnt;
			return;
		}
		++cnt;
		if (x + 1 == r && y + 1 == c) {
			cout << cnt;
			return;
		}
		++cnt;
	}
	else {
		move(size / 2, x, y);
		move(size / 2, x, y + size / 2);
		move(size / 2, x + size / 2, y);
		move(size / 2, x + size / 2, y + size / 2);
	}
}
int main()
{
	cin >> N >> r >> c;
	r++, c++;
	s = (int)pow(2, N);
	move(s, 1, 1);
}