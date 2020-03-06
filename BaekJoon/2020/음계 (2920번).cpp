#include <iostream>
using namespace std;
int p[10];

int main()
{
	for (int i = 1; i <= 8; i++) cin >> p[i];

	bool asc = true;
	bool des = true;
	for (int i = 1; i <= 8; i++) {
		if (p[i] != i) {
			asc = false;
			break;
		}
	}

	for (int i = 1; i <= 8; i++) {
		if (p[i] != 9 - i) {
			des = false;
			break;
		}
	}
	if (asc) cout << "ascending";
	else if (des) cout << "descending";
	else cout << "mixed";
}