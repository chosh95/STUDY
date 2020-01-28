#include <iostream>
#include <queue>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <iomanip>
using namespace std;

vector<pair<double, double>> base;
double dist[101][101];
int C, N;
bool visit[102];

bool decision(double d)
{
	for (int i = 0; i < 101; i++) visit[i] = false;
	visit[0] = true;
	queue<int> q;
	q.push(0);
	int count = 0;

	while (!q.empty()) {
		int here = q.front();
		q.pop();
		count++;
		for (int i = 0; i < N; i++) {
			if (!visit[i] && dist[here][i] <= d) {
				q.push(i);
				visit[i] = true;
			}
		}
	}
	return N == count;
}

double optimize()
{
	double lo = 0.0, hi = 1416.0;
	for (int i = 0; i < 100; i++) {
		double mid = (lo + hi) / 2.0;
		if (decision(mid)) {
			hi = mid;
		}
		else {
			lo = mid;
		}
	}
	return hi;
}

int main()
{
	cin >> C;
	while (C--) {
		cin >> N;
		base.clear();

		for (int i = 0; i < N; i++) {
			double x, y;
			cin >> x >> y;
			base.push_back({ x,y });
		}

		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
			{
				pair<double, double> point1 = base[i];
				pair<double, double> point2 = base[j];
				dist[i][j] = sqrt((point2.first - point1.first) * (point2.first - point1.first) + (point2.second - point1.second) * (point2.second - point1.second));
			}

		cout << fixed << setprecision(2);
		cout << optimize() << endl;
	}
}