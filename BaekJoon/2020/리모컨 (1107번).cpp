#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int N, M, res = 987654321;
int p[11];

void dfs(string cur) {
	
	for (int i = 0; i < 10; i++) {
		if (p[i] == -1) continue;
		
		string next = cur + to_string(i);
		res = min(res, abs(N - stoi(next)) + (int)next.length());

		if (next.size() < 6)
			dfs(next);
	}
}

int main()
{
	cin >> N >> M;
	for (int tmp, i = 0; i < M; i++) {
		cin >> tmp;
		p[tmp] = -1;
	}

	res = min(res, abs(100 - N));

	dfs("");

	cout << res;
}