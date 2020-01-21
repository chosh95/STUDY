#include <iostream>
using namespace std;
void print1(int n)
{
	for (int i = 1; i <= n / 2; i++) 
		cout << "* ";
	if (n % 2 != 0) cout << "*";
	cout << "\n";
}
void print2(int n)
{
	for (int i = 1; i <= n / 2; i++)
		cout << " *";
}
int main()
{
	int N;
	cin >> N;
	if (N == 1) {
		cout << "*";
		return 0;
	}
	for (int i = 1; i <= N; i++) {
		print1(N);
		print2(N);
		if(i!=N) cout << "\n";
	}
}