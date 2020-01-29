#include <iostream>
using namespace std;
int T, N, lo, hi;
const int max = 10000000;
//minFactor[i] = i가 가진 가장 작은 소수
///minFactorPower[i] = i의 소인수 분해에 minFactor[i]가 몇 승이 포함되는가
//factor[i] = i의 약수의 수
int minFactor[max + 1];
int minFactorPower[max + 1];
int factor[max + 1];

void eratosthenes()
{
	minFactor[0] = minFactor[1] = -1;
	for (int i = 2; i <= max; i++) minFactor[i] = i;
	for (int i = 2; i * i <= max; i++) {
		if (minFactor[i] == i) {
			for (int j = i * i; j <= max; j+= i)
				if (minFactor[j] == j)
					minFactor[j] = i;
		}
	}
}

void getFactor()
{
	factor[1] = 1;
	for (int i = 2; i <= max; i++) {
		if (minFactor[i] == i) {
			minFactorPower[i] = 1;
			factor[i] = 2;
		}
		else {
			int p = minFactor[i];
			int m = i / p;
			if (minFactor[i] != minFactor[m])
				minFactorPower[i] = 1;
			else
				minFactorPower[i] = minFactorPower[m] + 1;
			factor[i] = (factor[m] / minFactorPower[i]) * (minFactorPower[i] + 1);
		}
	}
}

int main()
{
	cin >> T;
	eratosthenes();
	getFactor();
	while (T--) {
		cin >> N >> lo >> hi;
		int count = 0;
		for (int i = lo; i <= hi; i++) {
			if (factor[i] == N)
				count++;
		}
		cout << count << endl;
	}
}