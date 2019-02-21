<<<<<<< HEAD
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
=======
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
>>>>>>> 7f36c76f4ad21fe245254ea3f1b3c6e1e3bbbd90
}