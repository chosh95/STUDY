#include <iostream>
using namespace std;
int N;
int p[81];
bool chk = false;

bool istrue(int n) {
	if (p[n] == p[n - 1]) return false;
	if (n == 1 || n == 2 || n==3) return true;
	int maxlen = n / 2;
	for (int i = 2; i <= maxlen; i++) {
		bool tmp = false;
		for (int j = 0; j < i; j++) {
			if (p[n - j] != p[n - j - i]) {
				tmp = true;
				break;
			}
		}
		if (!tmp) return false;
	}
	return true;
}

void dfs(int n) {
	if (n == N + 1) {
		chk = true;
		return;
	}
	for (int i = 1; i <= 3; i++) {
		p[n] = i;
		if (istrue(n)) {
			dfs(n + 1);
			if (chk) break;
		}
	}
}

int main()
{
	cin >> N;
	dfs(1);

	for (int i = 1; i <= N; i++)
		cout << p[i];
	return 0;
}