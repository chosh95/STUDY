#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N;
int p[51][51];
vector<int> res;

int main()
{
	cin >> N;

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			p[i][j] = 51;
			

	while (true) {
		int a, b;
		cin >> a >> b;
		if (a == b && a == -1) break;
		p[a][b] = p[b][a] = 1;
	}

	for (int i = 1; i <= N; i++) 
		for (int j = 1; j <= N; j++) 
			for (int k = 1; k <= N; k++) 
				if (p[j][i] != 51 && p[i][k] != 51)
					p[j][k] = min(p[j][k], p[j][i] + p[i][k]);
	
	int minNum = 52;
	for (int i = 1; i <= N; i++) {
		int cur = 0;
		for (int j = 1; j <= N; j++) {
			if (i == j) continue;
			cur = max(cur, p[i][j]);
		}
		if (minNum > cur) {
			res.clear();
			res.push_back(i);
			minNum = cur;
		}
		else if (minNum == cur) {
			res.push_back(i);
		}
	}

	cout << minNum << " " << res.size() << "\n";
	for (int x : res)
		cout << x << " ";
}