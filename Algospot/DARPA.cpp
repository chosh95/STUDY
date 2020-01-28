#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
using namespace std;

int C, N, M;
vector<double> location;

bool decision(int camera, double gap)
{
	double limit = -1;
	int install = 0;
	for (int i = 0; i < location.size(); i++) {
		if (limit <= location[i]) {
			++install;
			limit = location[i] + gap;
		}
	}
	return install >= camera;
}

double optimize(int camera)
{
	double lo = 0.0, hi = 241.0;
	for(int it = 0;it<100;it++){
		double mid = (lo + hi) / 2.0;
		if (decision(camera, mid))
			lo = mid;
		else
			hi = mid;
	}
	return lo;
}

int main()
{
	cin >> C;
	while (C--) {
		location.clear();
		cin >> N >> M;
		for (int i = 0; i < M; i++) {
			double num;
			cin >> num;
			location.push_back(num);
		}
		cout << fixed << setprecision(2);
		cout << optimize(N) << endl;
	}
}
