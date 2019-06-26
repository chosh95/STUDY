#include <iostream>
using namespace std;
int p[3001][3];
int parent[3001];
int find(int a) 
{
	if (parent[a] == a) return parent[a];
	else return parent[a] = find(parent[a]);
}
void merge(int a, int b)
{
	a = find(a);
	b = find(b);
	if (a == b) return;
	else parent[a] = b;
}


int main()
{
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		for (int i = 1; i <= N; i++) {
			cin >> p[i][0] >> p[i][1] >> p[i][2];
			parent[i] = i;
		}
		int res = N;
		for (int i = 1; i < N; i++) {
			for (int j = i + 1; j <= N; j++) {
				int x = (p[i][0] - p[j][0])*(p[i][0] - p[j][0]);
				int y = (p[i][1] - p[j][1])*(p[i][1] - p[j][1]);
				int d = x + y;
				int r = p[i][2] + p[j][2];
				if (d <= r*r) {
					if (find(i) != find(j)) {
						merge(i, j);
						res--;
					}
				}
			}
		}
		cout << res << "\n";
	}
}