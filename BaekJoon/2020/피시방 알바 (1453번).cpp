#include <iostream>
using namespace std;
int p[101];
int N;

int main()
{
	cin >> N;
	int res = 0;
	for (int tmp, i = 0; i < N; i++) {
		cin >> tmp;
		if (p[tmp] == 0) p[tmp] = 1;
		else res++;
	}
	cout << res;
}