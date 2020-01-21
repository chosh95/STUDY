#include <iostream>
using namespace std;
int main()
{
	int N;
	cin >> N;
	for (int i = 1; i <= N-1; i++) {
		for (int j = 1; j <= N - i; j++) cout << " ";
		cout << "*";
		for (int j = 1; j <= 2 * (i - 1) - 1; j++) cout << " ";
		if(i!=1) cout << "*";
		cout << endl;
	}
	for (int i = 1; i <= 2 * N - 1; i++)cout << "*";
}