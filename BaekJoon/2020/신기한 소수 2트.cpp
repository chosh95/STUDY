#include <iostream>
#include <algorithm>
#include <memory.h>
using namespace std;
int N;

bool isPrime(int cur) {
	if (cur == 1) return false;
	for (int i = 2; i * i <= cur; i++) {
		if (cur % i == 0) return false;
	}
	return true;
}

void dfs(int cur, int cnt) {
	if (cnt == N) {
		cout << cur << "\n";
		return;
	}

	for (int i = 1; i <= 9; i++) {
		int next = cur * 10 + i;
		if (isPrime(next))
			dfs(next, cnt + 1);
	}
}

int main()
{
	cin >> N;
	dfs(0, 0);
}