#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int C, N, P, L;
const int MAX = 1000000000 + 1;
const string  EXPAND_X = "X+YF";
const string  EXPAND_Y = "FX-Y";
int len[51]; //X나 Y의 세대별 길이 저장

void precalc()
{
	len[0] = 1; //X나 Y니까 길이는 1
	for (int i = 1; i <= 50; i++) {
		// X를 치환하면 "X+YF"니까 X의 전 세대 길이 + Y의 전 세대 길이  + '+'와'F'의 길이
		len[i] = min(MAX, len[i - 1] * 2 + 2); 
	}
}
char expand(const string& dragonCurve, int generation, int skip)
{
	if (generation == 0) {
		if (skip > dragonCurve.size()) exit(-1);
		return dragonCurve[skip];
	}
	for (int i = 0; i < dragonCurve.size(); i++) {
		if (dragonCurve[i] == 'X' || dragonCurve[i] == 'Y') {
			if (skip >= len[generation]) skip -= len[generation];
			else if (dragonCurve[i] == 'X')
				return expand(EXPAND_X, generation - 1, skip);
			else
				return expand(EXPAND_Y, generation - 1, skip);
		}
		else if (skip > 0) --skip;
		else return dragonCurve[i];
	}
	return '?';
}
int main()
{
	cin >> C;
	precalc();
	while (C--) {
		cin >> N >> P >> L;
		for (int i = 0; i < L; i++) 
			//문자열의 인덱스가 -1이 되기 때문에 p+i-1로 호출
			cout << expand("FX", N, P + i - 1); 
		cout << endl;
	}
}