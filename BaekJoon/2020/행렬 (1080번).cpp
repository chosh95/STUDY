#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int N, M;
int p[51][51], q[51][51];

void change(int a, int b) {
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (p[a + i][b + j] == 0) p[a + i][b + j] = 1;
			else p[a + i][b + j] = 0;
}

bool isPossible() {
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			if (p[i][j] != q[i][j])
				return false;

	return true;
}

int main()
{
	cin >> N >> M;
	string str;
	for (int i = 1; i <= N; i++) {
		cin >> str;
		for (int j = 1; j <= M; j++)
			p[i][j] = str[j-1] - '0';
	}
	for (int i = 1; i <= N; i++) {
		cin >> str;
		for (int j = 1; j <= M; j++)
			q[i][j] = str[j-1] - '0';
	}

	int res = 0;
	for (int i = 1; i <= N-2; i++)
		for (int j = 1; j <= M-2; j++)
			if (p[i][j] != q[i][j]) {
				change(i, j);
				res++;
			}


	if (!isPossible()) cout << "-1";
	else cout << res;
	
}