#include <iostream>
#include <queue>
#include <cmath>
using namespace std;
int C, N, K;
/* 난수 생성기, 이 방식을 써도 무관
struct RNG {
	unsigned int seed;
	RNG() : seed(1983) {}
	unsigned int next() {
		unsigned int ret = seed;
		seed = ((seed * 214013u) + 2531011u);
		return ret % 10000 + 1;
	}
};*/

int main()
{
	cin >> C;
	while (C--) {

		cin >> K >> N;
		queue<int> range;
		long long seed = 1983;
		int cnt = 0, sum = 0;

		for (int i = 0; i < N; i++) {
			int signal = (int)(seed % 10000 + 1);
			range.push(signal);
			sum += signal;
			
			while (sum > K) {
				sum -= range.front();
				range.pop();
			}

			if (sum == K) cnt++;

			seed = (seed * 214013 + 2531011) % (long long)(pow(2, 32));
		}
		cout << cnt << endl;
	}
}