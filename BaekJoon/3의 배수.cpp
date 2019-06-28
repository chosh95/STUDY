#include <iostream>
using namespace std;
int p[1001];
int main()
{
	int N;
	cin >> N;
	N /= 3;
	N -= 2;
	p[1] = 1;
	for (int i = 2, j = 2; i <= N; i++,j++) {
		p[i] = p[i - 1] + j;
	}
	cout << p[N];
}