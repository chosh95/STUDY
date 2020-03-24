#include <iostream>
using namespace std;
int N, K, S;
int p[401][401];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> K;
	for (int a, b, i = 1; i <= K; i++) {
		cin >> a >> b;
		p[a][b] = -1;
		p[b][a] = 1;
	}

	for(int j=1;j<=N;j++)
		for(int i=1;i<=N;i++)
			for (int k = 1; k <= N; k++) {
					if (p[i][j] == 1 && p[j][k] == 1) p[i][k] = 1;
					else if (p[i][j] == -1 && p[j][k] == -1) p[i][k] = -1;
			}

	cin >> S;
	for (int a, b, i = 1; i <= S; i++) {
		cin >> a >> b;
		cout << p[a][b] << "\n";
	}
}