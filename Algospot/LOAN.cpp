#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

int T, M;
double N, P;

double decision(double x)
{
	double ret = N;
	for (int i = 0; i < M; i++) {
		ret *= (1.0 + (P / 12.0) / 100.0);
		ret -= x;
	}
	return ret;
}

double optimize()
{
	//hi는 한달만에 원금을 다 갚는 최대치
	//이자가 최대 50%까지 가능하므로 원금에 1.5배
	double lo = 0, hi = 1.5*N;
	for(int i=0;i<100;i++) {
		double mid = (lo + hi) / 2.0;
		if (decision(mid) <= 0)
			hi = mid;
		else
			lo = mid;
	}
	return hi;
}


int main()
{
	cin >> T;
	while (T--) {
		cin >> N >> M >> P;
		cout << fixed << setprecision(10);
		cout << optimize() << endl;
	}
}
