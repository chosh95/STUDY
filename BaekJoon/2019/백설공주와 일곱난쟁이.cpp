#include <iostream>
using namespace std;
int p[10];
int q[10];
int sum;
void cal(void) 
{
	for (int i = 1; i <= 8; i++) {
		for (int j = i + 1; j <= 9; j++) {
			int tmp = sum;
			tmp -= p[i];
			tmp -= p[j];
			if (tmp == 100) {
				p[i] = p[j] = 0;
				return;
			}
		}
	}
}

int main()
{
	for (int i = 1; i <= 9; i++) {
		cin >> p[i];
		sum += p[i];
	}
	cal();
	for (int i = 1; i <= 9; i++) {
		if (p[i] != 0) cout << p[i] << "\n";
	}

}