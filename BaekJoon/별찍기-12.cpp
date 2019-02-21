<<<<<<< HEAD
#include <iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = n - i; j >= 1; j--) cout << " ";
		for (int k = 1; k <= i; k++) cout << "*";
		cout << endl;
	}
	for (int i = n - 1; i >= 1; i--) {
		for (int j = 1; j <= n - i; j++)	cout << " ";
		for (int k = 1; k <= i; k++) cout << "*";
		cout << endl;
	}
=======
#include <iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = n - i; j >= 1; j--) cout << " ";
		for (int k = 1; k <= i; k++) cout << "*";
		cout << endl;
	}
	for (int i = n - 1; i >= 1; i--) {
		for (int j = 1; j <= n - i; j++)	cout << " ";
		for (int k = 1; k <= i; k++) cout << "*";
		cout << endl;
	}
>>>>>>> 7f36c76f4ad21fe245254ea3f1b3c6e1e3bbbd90
}