#include <iostream>
using namespace std;

void printStar(int n)
{
	for (int i = 1; i <= n; i++) {
		cout << "* ";
	}
	cout << "\n";
}
void printStar2(int n)
{
	for (int i = 1; i <= n; i++) {
		cout << " *";
	}
	cout << "\n";
}

int main()
{
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		if (i % 2 == 1) printStar(N);
		else printStar2(N);
	}
}