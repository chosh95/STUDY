#include <iostream>
using namespace std;

int main()
{
	char p[9][9];
	int count = 0;
	for (int i = 1; i <= 8; i++) {
		for (int j = 1; j <= 8; j++) {
			cin >> p[i][j];
			if ((i + j) % 2 == 0 && p[i][j] == 'F') count++;
		}
	}
	cout << count;
}