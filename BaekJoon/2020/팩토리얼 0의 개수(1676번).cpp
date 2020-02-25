#include <iostream>
using namespace std;
int N, res;

void fact()
{
	res = 0;
	for (int i = 2; i <= N; i++) {
		int tmp = i;
		while (tmp % 5 ==0) {
			res++;	
			tmp /= 5;
		}
	}
}

int main()
{
	cin >> N;
	fact();
	cout << res;
}