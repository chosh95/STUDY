#include <iostream>
using namespace std;

int main()
{
	int A, B;
	cin >> A >> B;
	int p[2001];
	int k = 1;
	for (int i = 1;; i++) {
		for (int j = 1; j <= i; j++) {
			p[k++] = i;
		}
		if (k > B) break;
	}
	int res = 0;
	for (int i = A; i <= B; i++) {
		res += p[i];
	}
	cout << res;
}