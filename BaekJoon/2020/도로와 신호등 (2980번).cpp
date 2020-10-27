#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, L;
struct traffic {
	int D, R, G;
	traffic(int d, int r, int g) {
		D = d;
		R = r;
		G = g;
	}
};
vector<traffic> v;

int main()
{
	cin >> N >> L;
	for (int d,r,g,i = 0; i < N; i++) {
		cin >> d >> r >> g;
		v.push_back(traffic(d, r, g));
	}

	int pos = 0, cnt = 0, idx = 0; // 위치, 시간, 신호등 인덱스
	while (pos < L) {
		cnt++;
		pos++;
		if (idx < N && v[idx].D == pos) {
			int rest = cnt % (v[idx].R + v[idx].G);
			if (rest < v[idx].R) {
				cnt += v[idx].R - rest;
			}
			idx++;
		}
	}

	cout << cnt;
}