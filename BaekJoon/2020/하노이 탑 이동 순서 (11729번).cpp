#include <iostream>
using namespace std;
int N;
int p[21];

void hanoi(int n, int from, int by, int to) {
	
	if (n == 1) cout << from << " " << to << "\n";
	else {
		hanoi(n - 1, from, to, by);
		hanoi(1, from, by, to);
		hanoi(n - 1, by, from, to);
	}
}

int main()
{
	cin >> N;

	p[1] = 1;
	for (int i = 2; i <= N; i++) p[i] = p[i - 1] * 2 + 1;
	cout << p[N] << "\n";

	hanoi(N,1,2,3);
}