#include <iostream>
#include <algorithm>
using namespace std;
int p[500000];

int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> p[i];
	}
	sort(p, p + N);
	for (int i = 0; i < N; i++) {
		cout << p[i] << " ";
	}
}