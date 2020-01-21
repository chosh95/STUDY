#include <iostream>
using namespace std;
void print_star(int a, int b) {
	for (int i = 1; i <= a; i++) cout << ' ';
	for (int i = 1; i <= b; i++) cout << '*';
	cout << endl;
}
int main()
{
	int N;
	cin >> N;
	for (int i = 1; i <= 2 * N - 3; i += 2) {
		print_star(N-(i/2+1) , i);
	}
	print_star(0, 2 * N - 1);
	for (int i = 1; i <= N - 1;i++) {
		print_star(i, 2 * (N - i) - 1);
	}
}