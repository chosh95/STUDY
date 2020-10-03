#include <iostream>
using namespace std;
int a[10];
int b[10];

int main()
{
	int aSum = 0, bSum = 0;
	for (int i = 1; i <= 9; i++) {
		cin >> a[i];
		a[i] += a[i - 1];
	}
		
	for (int i = 1; i <= 9; i++) {
		cin >> b[i];
		b[i] += b[i - 1];
	}

	if (b[9] <= a[9]) {
		cout << "No";
		return 0;
	}

	bool isWin = false;
	for (int i = 1; i <= 9; i++) {
		if (a[i] > b[i - 1]) {
			isWin = true;
			break;
		}
	}
		
	if (isWin && a[9] < b[9])
		cout << "Yes";
	else
		cout << "No";
}