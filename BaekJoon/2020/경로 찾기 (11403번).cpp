#include <iostream>
using namespace std;
int N;
int p[101][101];

int main()
{
	cin >> N;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			cin >> p[i][j];

	for (int j = 1; j <= N; j++) { //중간점
		for (int i = 1; i <= N; i++) { //시작점
			for (int k = 1; k <= N; k++) { //도착점
				if (p[i][j] == 1 && p[j][k] == 1) p[i][k] = 1;
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cout << p[i][j] << " ";
		}
		cout << endl;
	}
	
}