#include <iostream>
#include <algorithm>
#include <memory.h>
using namespace std;
int N, M;
//vector<int> v[101];
int v[101][101]; //x가 y를 만났는가


int main()
{
	cin >> N >> M;
	memset(v, 9999, sizeof(v));
	for (int i = 1; i <= M; i++) {
		int a, b;
		cin >> a >> b;
		v[a][b] = 1;
		v[b][a] = 1;
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= N; k++) {
				v[j][k] = min(v[j][k], v[j][i] + v[i][k]);
			}
		}
	}
	int sum = 9999;
	int idx = 0;
	for (int i = 1; i <= N; i++) {
		int tmp = 0;
		for (int j = 1; j <= N; j++) {
			tmp += v[i][j];
		}
		if (sum > tmp) {
			sum = tmp;
			idx = i;
		}
	}
	cout << idx;
}
