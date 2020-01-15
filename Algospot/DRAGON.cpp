#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int C, N, P, L;
const int MAX = 1000000000 + 1;
const string  EXPAND_X = "X+YF";
const string  EXPAND_Y = "FX-Y";
int len[51]; //X�� Y�� ���뺰 ���� ����

void precalc()
{
	len[0] = 1; //X�� Y�ϱ� ���̴� 1
	for (int i = 1; i <= 50; i++) {
		// X�� ġȯ�ϸ� "X+YF"�ϱ� X�� �� ���� ���� + Y�� �� ���� ����  + '+'��'F'�� ����
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
			//���ڿ��� �ε����� -1�� �Ǳ� ������ p+i-1�� ȣ��
			cout << expand("FX", N, P + i - 1); 
		cout << endl;
	}
}