#include <iostream>
using namespace std;

int main()
{
	int N,res = 0;
	cin >> N;
	for (int i = 1; i <= 5; i++) {
		int a;
		cin >> a;
		if (a == N) res++;
	}
	cout << res;
}