#include <iostream>
using namespace std;
int L, P;
int main()
{
	cin >> L >> P;
	int space = L * P;
	int p[6], r[6];
	for (int i = 1; i <= 5; i++) {
		cin >> p[i];
		r[i] = p[i] - space;
	}
	for (int i = 1; i <= 5; i++) {
		cout << r[i] << " ";
	}

}