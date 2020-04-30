#include <iostream>
#include <algorithm>
using namespace std;
int p[6];

int main()
{
	for (int i = 1; i <= 5; i++) cin >> p[i];

	for (int i = 5; i >= 1; i--) {
		for (int j = 1; j < i; j++) {
			if (p[j] > p[j+1]) {
				swap(p[j], p[j+1]);
				for (int k = 1; k <= 5; k++)
					cout << p[k] << " ";
				cout << endl;
			}
		}
	}
}