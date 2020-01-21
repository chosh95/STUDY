#include <iostream>
using namespace std;
int N;
void printBlankStar(int n) {
	for (int i = 1; i <= n; i++) cout << " ";
	cout << "*";
}
int main()
{
	cin >> N;
	if (N % 2 == 0) {
		cout << "I LOVE CBNU";
		return 0;
	}
	else {
		for (int i = 1; i <= N; i++) cout << "*";
		cout << "\n";

		printBlankStar(N / 2); 
		cout << "\n";

		for (int i = 2; i <= N / 2 + 1 ; i++) {
			printBlankStar(N / 2 + 1 - i);
			printBlankStar(2 * (i - 1) - 1);
			if(i!=N/2+1)cout << "\n";
		}
	}

}