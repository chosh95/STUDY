#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int p[51];
int a[51];
int k;
void dfs(int idx, int count)
{
	if (idx > k+1) return;
	if (count == 6) {
		for (int i = 1; i <= k; i++) {
			if (a[i] == 0) continue;
			printf("%d ", a[i]);
		}
		printf("\n");
		return;
	}
	a[idx] = p[idx];
	dfs(idx + 1, count + 1);
	a[idx] = 0;
	dfs(idx + 1, count);
}
int main()
{
	while (true)
	{
		cin >> k;
		if (k == 0) break;
		for (int i = 1; i <= k; i++) 
			cin >> p[i];
		dfs(1, 0);
		printf("\n");
	}
	return 0;
}