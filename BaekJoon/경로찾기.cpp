#include <iostream>
#include <queue>
using namespace std;
int p[101][101];

int main()
{
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> p[i][j];
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= N; k++) {
				if (p[j][k] == 1) continue;
				if (p[j][i]==1 && p[i][k]==1) p[j][k] = 1;
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++)
			cout << p[i][j] << " ";
		cout << endl;
	}
}
