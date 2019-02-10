#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	int T;
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> T;
	for (int i = 1; i <= T; i++) {
		int A, B;
		cin >> A >> B;
		cout << A + B << "\n";
	}
}