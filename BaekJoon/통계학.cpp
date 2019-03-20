#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
int p[500002];
int v[8001];

int main()
{
	int N;
	double sum = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> p[i];
		sum += p[i];
	}
	cout << round(sum/N) << endl;
	sort(p, p + N);
	cout << p[N / 2] << endl;
	for (int i = 0; i < N; i++) v[p[i] + 4000]++;
	int maxnum = 0, maxindex = 0;
	int maxindex2 = 0, maxnum2 = 0;
	bool tmp = false;
	for (int i = 0; i < 8001; i++) {
		if (v[i] > maxnum) {
			maxnum = v[i];
			maxindex = i-4000;
			tmp = false;
		}
		else if (v[i] == maxnum && tmp == false) {
			maxindex2 = i - 4000;
			maxnum2 = maxnum;
			tmp = true;
		}
	}
	if (maxnum == maxnum2) cout << maxindex2 << endl;
	else cout << maxindex << endl;
	cout << p[N - 1] - p[0];
}