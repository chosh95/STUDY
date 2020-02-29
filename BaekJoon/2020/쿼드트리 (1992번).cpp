#include <iostream>
using namespace std;
int N;
int p[65][65];

bool isQuad(int n, int x, int y) {
	int startPoint = p[x][y];
	for (int i = x; i < x + n; i++) 
		for (int j = y; j < y + n; j++) 
			if (p[i][j] != startPoint) return false;
	return true;
}

void quad(int n, int x, int y) {
	if (n == 1) {
		cout << p[x][y];
		return;
	}
	if (isQuad(n, x, y)) cout << p[x][y];
	else {
		cout << "(";
		quad(n / 2, x, y);
		quad(n / 2, x , y + n/2);
		quad(n / 2, x + n / 2, y);
		quad(n / 2, x + n / 2, y + n / 2);
		cout << ")";
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	char a;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> a;
			if (a == '1') p[i][j] = 1;
			else p[i][j] = 0;
		}
	}

	quad(N, 1, 1);
}