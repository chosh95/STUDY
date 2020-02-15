#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
int n, k, s;
int p[401][401];
void floyd()
{
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (p[i][j] == 0) {
					if (p[i][k] == 1 && p[k][j] == 1)
						p[i][j] = 1;
					if (p[i][k] == -1 && p[k][j] == -1)
						p[i][j] = -1;
				}
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> k;
	for (int a, b, i = 0; i < k; i++) {
		cin >> a >> b;
		p[a][b] = -1;
		p[b][a] = 1;
	}

	floyd();

	cin >> s;
	for (int a, b, i = 0; i < s; i++) {
		cin >> a >> b;
		cout << p[a][b] << "\n";
	}
}