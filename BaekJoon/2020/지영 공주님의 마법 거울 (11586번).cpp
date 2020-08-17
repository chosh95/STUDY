#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int N, K;
char p[101][101];

int main()
{
	cin >> N;
	string str;
	for (int i = 0; i < N; i++) {
		cin >> str;
		for (int j = 0; j < N; j++)
			p[i][j] = str[j];
	}
	cin >> K;

	if (K == 1) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cout << p[i][j];
			}
			cout << endl;
		}
	}
	else if (K == 2) {
		for (int i = 0; i < N; i++) {
			for (int j = N - 1; j >= 0; j--) {
				cout << p[i][j];
			}
			cout << endl;
		}
	}
	else {
		for (int i = N - 1; i >= 0; i--) {
			for (int j = 0; j < N; j++) {
				cout << p[i][j];
			}
			cout << endl;
		}
	}
}