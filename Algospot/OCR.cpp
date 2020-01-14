#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
int m, q, n;
int R[101];
double B[501];
double T[501][501];
double M[501][501];
double dp[102][501];
int choice[102][501];
string word[501];
void init()
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= m; j++) {
			dp[i][j] = 1.0;
		}
	}
}

double recognize(int segment, int previousMatch)
{
	if (segment == n) return 0;
	double& res = dp[segment][previousMatch];
	if (res != 1.0) return res;
	res = -1e200;
	int& choose = choice[segment][previousMatch];
	for (int i = 1; i <= m; i++) {
		double cand = T[previousMatch][i] + M[i][R[segment]] + recognize(segment + 1, i);
		if (res < cand) {
			res = cand;
			choose = i;
		}
	}
	return res;
}

string reconstruct(int segment, int previousMatch) {
	int choose = choice[segment][previousMatch];
	string res = word[choose];
	if (segment < n - 1) {
		res = res + " " + reconstruct(segment + 1, choose);
	}
	return res;
}
int main()
{
	cin >> m >> q;
	for (int i = 1; i <= m; i++) cin >> word[i];
	for (int i = 1; i <= m; i++) {
		cin >> B[i];
		B[i] = log(B[i]);
	}
	for (int i = 0; i <= m; i++) 
		for (int j = 1; j <= m; j++) {
			if (i == 0) T[i][j] = B[j];
			else {
				cin >> T[i][j];
				T[i][j] = log(T[i][j]);
			}
		}
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= m; j++) {
			cin >> M[i][j];
			M[i][j] = log(M[i][j]);
		}
	while (q--) {
		cin >> n;
		init();
		for (int i = 0; i < n; i++) {
			string tmp;
			cin >> tmp;
			for (int j = 1; j <= m; j++) {
				if (tmp == word[j]) {
					R[i] = j;
					break;
				}
			}
		}
		recognize(0, 0);
		cout << reconstruct(0, 0) << endl;
	}
	return 0;
}