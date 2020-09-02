#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int N, res = 1;
char p[51][51];

void checkSum() {
	int tmp = 1;
	for (int i = 1; i <= N; i++) {
		tmp = 1;
		for (int j = 1; j <= N - 1; j++) {
			if (p[i][j] == p[i][j + 1])
				tmp++;
			else
				tmp = 1;
			res = max(res, tmp);
		}
	}

	for (int i = 1; i <= N; i++) {
		tmp = 1;
		for (int j = 1; j <= N - 1; j++) {
			if (p[j + 1][i] == p[j][i])
				tmp++;
			else
				tmp = 1;
			res = max(res, tmp);
		}
	}
}

int main()
{
	cin >> N;
	for (int i = 1; i <= N; i++) {
		string str;
		cin >> str;
		for (int j = 1; j <= N; j++) {
			p[i][j] = str[j - 1];
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N - 1; j++) {
			swap(p[i][j],p[i][j+1]);
			checkSum();
			swap(p[i][j], p[i][j+1]);

			swap(p[j][i], p[j+1][i]);
			checkSum();
			swap(p[j][i], p[j+1][i]);
		}
	}

	cout << res;
}