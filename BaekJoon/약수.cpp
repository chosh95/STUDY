#include <iostream>
#include <algorithm>
using namespace std;

int p[100];
int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) cin >> p[i];
	sort(p, p + N);
	cout << p[0] * p[N - 1];
}