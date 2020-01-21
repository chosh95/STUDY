#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;
int maxp[2][3]; // p[i][0] 최소값 p[i][1] 최대값 p[i][2] 원소값
int minp[2][3];
int tmp[3];
int main()
{
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		scanf("%d%d%d", &tmp[0],&tmp[1],&tmp[2]);
		minp[1][0] = min(minp[0][0], minp[0][1]) + tmp[0];
		minp[1][1] = min(min(minp[0][0], minp[0][1]), minp[0][2]) + tmp[1];
		minp[1][2] = min(minp[0][1], minp[0][2]) + tmp[2];
		maxp[1][0] = max(maxp[0][0], maxp[0][1]) + tmp[0];
		maxp[1][1] = max(max(maxp[0][0], maxp[0][1]), maxp[0][2]) + tmp[1];
		maxp[1][2] = max(maxp[0][1], maxp[0][2]) + tmp[2];
		minp[0][0] = minp[1][0];
		minp[0][1] = minp[1][1];
		minp[0][2] = minp[1][2];
		maxp[0][0] = maxp[1][0];
		maxp[0][1] = maxp[1][1];
		maxp[0][2] = maxp[1][2];
	}
	cout << max(max(maxp[1][0],maxp[1][1]),maxp[1][2]) << " " << min(min(minp[1][0],minp[1][1]),minp[1][2]);
}