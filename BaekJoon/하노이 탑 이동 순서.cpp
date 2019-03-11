#include <iostream>
using namespace std;
int N;

void hanoi(int n, int from, int to)
{
	if (n == 1) {
		printf("%d %d\n", from, to);
	}
	else {
		hanoi(n - 1, from, 6 - from - to);
		printf("%d %d\n", from, to);
		hanoi(n-1, 6-from-to, to);
	}
}

int main()
{
	cin >> N;
	cout << (1 << N) - 1 << endl;
	hanoi(N, 1, 3);
	return 0;
}