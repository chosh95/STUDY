#include <iostream>
using namespace std;

void printBlankStar(int n) {
	for (int i = 1; i <= n; i++) cout << " ";
	cout << "*";
}

int main()
{
	int N;
	cin >> N;
	if (N == 1) { cout << "*"; return 0; }

	printBlankStar(N-1);
	cout << "\n";
	for (int i = 1; N - i > 0;i++) {
		printBlankStar(N-i-1);
		printBlankStar(2*i-1);
		if(i!=N-1)cout << "\n";
	}
}