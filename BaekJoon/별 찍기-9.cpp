#include <iostream> 
using namespace std;
int main()
{
	int N;
	cin >> N;
	for (int i = N; i >= 1; i--) {
		for (int j = 0; j < N - i; j++) cout <<" ";
		for (int k = i * 2 - 1; k >= 1; k--)cout << "*";
		if(N!=1) cout << "\n";
	}
	for (int i = 2; i <= N; i++) {
		for (int j = 0; j < N - i; j++) cout << " ";
		for (int k = i * 2 - 1; k >= 1; k--)cout << "*";
		if(i!=N) cout << "\n";
	}
}