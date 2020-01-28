#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int C, N, K;
int L[5001];
int M[5001];
int G[5001];


bool decision(int x)
{
	int count = 0;
	for (int i = 0; i < N; i++) {
		if (x >= L[i] - M[i]) {
			int cur = min(x, L[i]);
			count += (cur - (L[i] - M[i])) / G[i] + 1;
		}
	}
	return count >= K;
}

int optimize()
{
	int lo = 0, hi = 8030001;
	while (lo + 1 < hi) {
		int mid = (lo + hi) / 2;
		if (decision(mid)) {
			hi = mid;
		}
		else
			lo = mid;
	}
	return hi;
}
int main()
{
	cin >> C;
	while (C--) {
		cin >> N >> K;
		for (int i = 0; i < N; i++) 
			cin >> L[i] >> M[i] >> G[i];
		cout << optimize() << endl;
	}
}