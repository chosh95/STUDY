#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;
int p[21][21];
bool v[21];
int N, res = 999999;

void dfs(int n, int cnt)
{
	if (cnt == N / 2) {
		vector<int> A;
		vector<int> B;
		for (int i = 1; i <= N; i++) {
			if (v[i] == true) A.push_back(i);
			else B.push_back(i);
		}
		int sumA = 0, sumB = 0;
		for (int i = 0; i < N / 2; i++) {
			for (int j = 0; j < N / 2; j++) {
				sumA += p[A[i]][A[j]];
			}
		}
		for (int i = 0; i < N / 2; i++) {
			for (int j = 0; j < N / 2; j++) {
				sumB += p[B[i]][B[j]];
			}
		}
		int tmp = abs(sumA - sumB);
		if (res > tmp) res = tmp;
		return;
	}
	for (int i = n + 1; i <= N; i++) {
		if (v[i] == false) {
			v[i] = true;
			dfs(i, cnt + 1);
			v[i] = false;
		}
	}
}

int main()
{
	cin >> N;
	for (int i = 1; i <= N; i++) 
		for (int j = 1; j <= N; j++) 
			cin >> p[i][j];
	
	dfs(0, 0);

	cout << res;

}
