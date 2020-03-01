#include <iostream>
using namespace std;
int N, M, K;

int main()
{
	cin >> N >> M >> K;
	int rest = 0, teamCnt = 0;
	if (N >= M * 2) 
		teamCnt = M;
	else
		teamCnt = N / 2;
	rest = N + M - teamCnt * 3;
	K -= rest;
	while (K > 0) {
		K-=3;
		teamCnt--;
	}
	cout << teamCnt;
}