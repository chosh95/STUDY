#include <iostream>
#include <algorithm>
using namespace std;
int D, N;
int d[300001];
int n[300001];
int len[300001];

int main()
{
	cin >> D >> N;
	for (int i = 1; i <= D; i++)
		cin >> d[i];
	for (int i = 1; i <= N; i++)
		cin >> n[i];

	int min = len[1] = d[1];
	for (int i = 2; i <= D; i++) {
		if (min > d[i]) min = d[i];
		len[i] = min;
	}

	int idx = D;
	for (int i = 1; i <= N; i++) {
		while (idx >= 1 && len[idx] < n[i]) idx--;
		idx--;
	}

	if (idx < 0) cout << 0;
	else cout << idx + 1;
}