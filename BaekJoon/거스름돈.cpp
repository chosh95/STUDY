#include <iostream>
#include <algorithm>
using namespace std;
int p[7] = { 500,100,50,10,5,1 };
int cal(int n)
{
	int cnt = 0;
	for (int i = 0; i < 6; i++) {
		if (n == 0) return cnt;
		while (true) {
			if (n == 0) return cnt;
			if (n >= p[i]) {
				cnt += (n / p[i]);
				n %= p[i];
			}
			else break;
		}
	}
}

int main()
{
	int N, cnt;
	cin >> N;
	cnt = cal(1000-N);
	cout << cnt;
}