#include <iostream>
#include <memory.h>
using namespace std;
int N;
long long cnt;
int boundary[10][10] = {
		{0, 0, 0, 0, 0, 0, 0, 1, 0, 0}, //0
		{0, 0, 1, 0, 1, 0, 0, 0, 0, 0}, //1
		{0, 1, 0, 1, 0, 1, 0, 0, 0, 0}, //2
		{0, 0, 1, 0, 0, 0, 1, 0, 0, 0}, //3
		{0, 1, 0, 0, 0, 1, 0, 1, 0, 0}, //4
		{0, 0, 1, 0, 1, 0, 1, 0, 1, 0}, //5
		{0, 0, 0, 1, 0, 1, 0, 0, 0, 1}, //6
		{1, 0, 0, 0, 1, 0, 0, 0, 1, 0}, //7
		{0, 0, 0, 0, 0, 1, 0, 1, 0, 1}, //8
		{0, 0, 0, 0, 0, 0, 1, 0, 1, 0} //9
};
int map[10][1001];

int pwd(int t, int n)
{
	if (map[t][n] != -1) return map[t][n];
	map[t][n] = 0;

	for (int i = 0; i <= 9; i++) {
		if (boundary[t][i]) {
			map[t][n] += pwd(i, n - 1) % 1234567;
		}
	}
	return map[t][n];
}

int main()
{
	int T;
	cin >> T;
	while (T--) {
		cin >> N;
		cnt = 0;
		memset(map, -1, sizeof(map));
		for (int i = 0; i <= 9; i++) map[i][1] = 1;
		for (int i = 0; i <= 9; i++) {
			cnt += (pwd(i, N) % 1234567);
		}
		cout << cnt%1234567<< endl;
	}
}