<<<<<<< HEAD
#include <iostream>
using namespace std;
int main()
{
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= i; j++) cout << "*";
		for (int j = (N - i) * 2; j >= 1; j--) cout << " ";
		for (int j = 1; j <= i; j++) cout << "*";
		cout << endl;
	}
	for (int i = N - 1; i >= 1; i--) {
		for (int j = 1; j <= i; j++) cout << "*";
		for (int j = (N - i) * 2; j >= 1; j--) cout << " ";
		for (int j = 1; j <= i; j++) cout << "*";
		cout << endl;
	}
}
=======
#include <iostream>
using namespace std;
int main()
{
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= i; j++) cout << "*";
		for (int j = (N - i) * 2; j >= 1; j--) cout << " ";
		for (int j = 1; j <= i; j++) cout << "*";
		cout << endl;
	}
	for (int i = N - 1; i >= 1; i--) {
		for (int j = 1; j <= i; j++) cout << "*";
		for (int j = (N - i) * 2; j >= 1; j--) cout << " ";
		for (int j = 1; j <= i; j++) cout << "*";
		cout << endl;
	}
}
>>>>>>> 7f36c76f4ad21fe245254ea3f1b3c6e1e3bbbd90
