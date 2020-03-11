#include <iostream>
#include <algorithm>
using namespace std;
int N, M;
int nx, ny, mx, my;

int main()
{
	cin >> N >> M;

	if (N % 4 != 0) nx = N / 4 + 1;
	else nx = N / 4;
	
	ny = N % 4;
	if (ny == 0) ny = 4;

	if (M % 4 != 0) mx = M / 4 + 1;
	else mx = M / 4;
	my = M % 4;
	if (my == 0) my = 4;

	cout << abs(nx - mx) + abs(ny - my);
}