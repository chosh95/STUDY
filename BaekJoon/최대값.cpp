<<<<<<< HEAD
#include <iostream>
using namespace std;

int main()
{
	int p[10];
	int mn = 0, mi = 0;
	for (int i = 1; i <= 9; i++) {
		cin >> p[i];
		if (p[i] > mn) {
			mn = p[i];
			mi = i;
		}
	}
	cout << mn << "\n" << mi;
=======
#include <iostream>
using namespace std;

int main()
{
	int p[10];
	int mn = 0, mi = 0;
	for (int i = 1; i <= 9; i++) {
		cin >> p[i];
		if (p[i] > mn) {
			mn = p[i];
			mi = i;
		}
	}
	cout << mn << "\n" << mi;
>>>>>>> 7f36c76f4ad21fe245254ea3f1b3c6e1e3bbbd90
}