#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int T, N, K;
int R[1001];
int C[1001];

bool decision(double x)
{
	vector<double> v;
	for (int i = 0; i < N; i++)
		v.push_back(x * C[i] - R[i]);
	sort(v.begin(), v.end());
	double sum = 0;
	for (int i = N - K; i < N; i++)
		sum += v[i];
	return sum >= 0;
}

double optimize()
{
	double lo = -1e-9, hi = 1;
	for (int i = 0; i < 100; i++) {
		double mid = (lo + hi) / 2;
		//누적 등수 mid를 할 수 있나?
		if (decision(mid)) 
			hi = mid;
		else
			lo = mid;
	}
	return mid;
}

int main()
{
	cin >> T;
	while (T--) {
		cin >> N >> K;
		memset(C, 0, sizeof(C));
		memset(R, 0, sizeof(R));
		for (int i = 0; i < N; i++)
			cin >> R[i] >> C[i];
		cout << fixed << setprecision(10);
		cout << optimize() << endl;
	}
}