#include <iostream>
using namespace std;
char c[101][101];

int main()
{
	int N, garo = 0, sero = 0;
	cin >> N;

	for (int i = 1; i <= N; i++) 
		for (int j = 1; j <= N; j++) 
			cin >> c[i][j];
		
	for (int i = 1; i <= N; i++) {
		int cnt = 0;
		for (int j = 1; j <= N; j++) {
			if (c[i][j] == '.') cnt++;
			else cnt = 0;
			if (cnt == 2) garo++;
		}
	}
	for (int i = 1; i <= N; i++) {
		int cnt = 0;
		for (int j = 1; j <= N; j++) {
			if (c[j][i] == '.') cnt++;
			else cnt = 0;
			if (cnt == 2) sero++;
		}
	}
	cout << garo << " " << sero;
}