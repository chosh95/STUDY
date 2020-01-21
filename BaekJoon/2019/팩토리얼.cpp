#include <iostream>
using namespace std;
int p[502];
void fact(long long n) {
	for (int i = 1; i <= n; i++) {
		int tmp = i;
		p[i] = p[i - 1];
		while (tmp%5==0) {
			if (tmp % 5 == 0) {
				tmp /= 5;
				p[i]++;
			}
			else break;
		}
	}
}


int main()
{
	long long N;
	cin >> N;
	p[0] = p[1] = 0;
	fact(N);
	cout << p[N];
}