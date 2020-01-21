#include <iostream>
#include <math.h>
using namespace std;
long long N, M;
int main()
{
	cin >> N >> M;
	N = abs(N - M);
	cout << N;
}