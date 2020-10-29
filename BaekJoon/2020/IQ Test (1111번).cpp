#include <iostream>
#include <algorithm>
using namespace std;
int N;
int p[51];

int main()
{
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> p[i];

	if (N == 1) {
		cout << "A";
		return 0;
	}
	if (N == 2) {
		if (p[1] == p[2]) {
			cout << p[1];
			return 0;
		}
		else {
			cout << "A";
			return 0;
		}
	}
	
	int a, b;
	if (p[1] == p[2]) a = 0;
	else a = (p[3] - p[2]) / (p[2] - p[1]);
	b = p[2] - p[1] * a;

	for (int i = 1; i < N; i++) {
		if (p[i] * a + b != p[i + 1]) {
			cout << "B";
			return 0;
		}
	}

	cout << p[N] * a + b;
}