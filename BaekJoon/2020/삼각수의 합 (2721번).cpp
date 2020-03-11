#include <iostream>
using namespace std;
long long T[302];
long long W[302];
int Test, N;

void sum() {
	T[0] = 0;
	for (int i = 1; i <= 301; i++) 
		T[i] = T[i - 1] + i;
}

void triSum() {
	W[0] = 0;
	for (int i = 1; i <= 300; i++) 
		W[i] = W[i - 1] + i * T[i + 1];
	
}

int main()
{
	cin >> Test;

	sum();
	triSum();

	while (Test--) {
		cin >> N;
		cout << W[N] << "\n";
	}
}