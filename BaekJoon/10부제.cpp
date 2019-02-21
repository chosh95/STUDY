<<<<<<< HEAD
#include <iostream>
using namespace std;

int main()
{
	int N,res = 0;
	cin >> N;
	for (int i = 1; i <= 5; i++) {
		int a;
		cin >> a;
		if (a == N) res++;
	}
	cout << res;
=======
#include <iostream>
using namespace std;

int main()
{
	int N,res = 0;
	cin >> N;
	for (int i = 1; i <= 5; i++) {
		int a;
		cin >> a;
		if (a == N) res++;
	}
	cout << res;
>>>>>>> 7f36c76f4ad21fe245254ea3f1b3c6e1e3bbbd90
}