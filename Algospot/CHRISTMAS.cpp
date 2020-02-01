#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int C, N, K;
const int mod = 20091101;

int waysToBuy(const vector<int> &psum)
{
	vector<long long> count(K, 0);
	for (int i = 0; i < psum.size(); i++)
		count[psum[i]]++;

	int res = 0;
	for (int i = 0; i < K; i++) {
		if (count[i] >= 2)
			res = (res + (count[i] * (count[i] - 1) / 2)) % mod;
	}
	return res;
}

int maxBuy(const vector<int> &psum)
{
	vector<int> res(psum.size(), 0);
	vector<int> prev(K, -1);
	for (int i = 0; i < psum.size(); i++) {
		if (i > 0) res[i] = res[i - 1];
		else res[i] = 0;

		int loc = prev[psum[i]];
		if (loc != -1) res[i] = max(res[i], res[loc] + 1);
		prev[psum[i]] = i;
	}
	return res.back();
}

int main()
{
	cin >> C;
	while (C--) {
		cin >> N >> K;
		vector<int> p(N, 0);
		vector<int> psum(N + 1, 0);
		for (int i = 0; i < N; i++) 
			cin >> p[i];

		psum[0] = 0;
		for (int i = 1; i <= N; i++) {
			psum[i] = (psum[i - 1] + p[i - 1]) % K;
		}
		cout << waysToBuy(psum) << " " << maxBuy(psum) << endl;
	}
}