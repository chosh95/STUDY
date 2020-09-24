#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, W, L;
int p[1001];
int position[1001];

bool isPossible() {
	for (int i = 1; i <= N; i++) {
		if (position[i] <= W) return false;
	}
	return true;
}

int main()
{
	cin >> N >> W >> L;
	for (int i = 1; i <= N; i++)
		cin >> p[i];
	
	int curWeight = 0, carIdx = 1;
	int time = 0;

	while(!isPossible()){
		time++;
		for (int j = 1; j < carIdx; j++) {
			if (position[j] > W) continue;
			position[j] += 1;
			if (position[j] == W + 1) curWeight -= p[j];
		}
		if (curWeight + p[carIdx] <= L) {
			curWeight += p[carIdx];
			position[carIdx] = 1;
			carIdx++;
		}
	}

	cout << time;
}