#include <iostream>
#include <string>
using namespace std;
int N;
char p[3000][3000] = { ' ' };
void star(int x, int y, int size)
{
	if (size == 1){
		p[x][y] = '*';
		return;
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i == 1 && j == 1) continue;
			star(x + (size / 3)*i, y + (size / 3)*j, size / 3);
		}
	}
}


int main()
{
	cin >> N;
	star(0, 0, N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if(p[i][j]=='*') cout << p[i][j];
			else cout << ' ';
		}
		cout << "\n";
	}
	return 0;
}