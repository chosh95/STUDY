#include <iostream>
#include <algorithm>
using namespace std;
int C;
int clockState[16];
int swtch[10][16] = {
	{1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0},
	{0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1},
	{1, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0},
	{1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
	{0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
	{0, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1},
	{0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0}
};
bool isAligned()
{
	for (int i = 0; i < 16; i++) {
		if (clockState[i] != 12) return false;
	}
	return true;
}
void pushSwtch(int swtchNum, int pushNum) {
	for (int j = 0; j < pushNum; j++) {
		for (int i = 0; i < 16; i++) {
			if (swtch[swtchNum][i] == 1) {
				clockState[i] += 3;
				if (clockState[i] == 15) clockState[i] = 3;
			}
		}
	}
}
int sync(int currentSwtch)
{
	if (currentSwtch == 10) {
		if (isAligned()) return 0;
		else return 99999;
	}
	int ret = 99999;
	for (int i = 0; i < 4; i++) {
		pushSwtch(currentSwtch, i);	//i번 스위치를 누르고
		ret = min(ret, i + sync(currentSwtch + 1)); // 최소값을 찾는다.
		pushSwtch(currentSwtch, 4-i); //시계를 다시 원상복구
	}
	return ret;
}
int main()
{
	cin >> C;
	while (C--) {
		for (int i = 0; i < 16; i++)
			cin >> clockState[i];
		int res = sync(0);
		if (res == 99999) cout << "-1\n";
		else cout << res << "\n";
	}
}
