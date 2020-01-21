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
	for (int i = 0; i < N; i++)
		print_star(i, 2 * N - (2 * i + 1));
}