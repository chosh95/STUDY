#include <iostream>
using namespace std;
int N, blue, white;
int p[129][129];

bool isTrue(int x, int y, int size, int color) {
	for (int i = x; i < x + size; i++) {
		for (int j = y; j < y + size; j++) {
			if (p[i][j] != color) return false;
		}
	}
	return true;
}

void paper(int x, int y, int size) {
	if (isTrue(x, y, size, 0)) {
		white++;
		return;
	}
	if (isTrue(x, y, size, 1)) {
		blue++;
		return;
	}

	paper(x, y, size / 2);
	paper(x + size / 2, y, size / 2);
	paper(x, y + size / 2, size / 2);
	paper(x + size / 2, y + size / 2, size / 2);
}

int main()
{
	cin >> N;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			cin >> p[i][j];

	paper(1, 1, N);

	cout << white << "\n" << blue;
}