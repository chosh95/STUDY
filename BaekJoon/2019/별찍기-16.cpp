#include <iostream>
using namespace std;
void print_star(int a, int b)
{
	for (int i = 1; i <= a; i++) cout << " ";
	for (int i = 1; i < b; i++) cout << "* ";
	cout << "*";
}
int main()
{
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		print_star(N - i, i);
		if(i!=N) cout << "\n";
	}
}