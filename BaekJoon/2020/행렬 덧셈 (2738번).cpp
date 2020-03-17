#include <iostream>
using namespace std;
int N, K;
int a[101][101];
int b[101][101];

int main()
{
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= K; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int tmp, j = 1; j <= K; j++) {
			cin >> tmp;
			cout << a[i][j] + tmp << " ";
		}
		cout << "\n";
	}
}