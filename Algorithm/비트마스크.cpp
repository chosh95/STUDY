#include <iostream>
#include <intrin.h> //__popcnt ���� ���
using namespace std;

//n���� 1�� ���� ��Ʈ ��ȯ
int fullBit(int n)
{
	return (1 << n) - 1;
}

//bit�� n��° ��ġ�� ���Ҹ� �߰�
int insertBit(int bit, int n)
{
	bit |= (1 << n);
	return bit;
}

//bit�� n��° ��ġ�� ���Ұ� ���ԵǾ��ִ°�
bool isContain(int bit, int n)
{
	bool res = (bit & (1 << n));
	return res;
}

//bit�� n��° ��ġ�� ���Ҹ� ����
int removeBit(int bit, int n)
{
	//bit -= (1<<n)�� bit�� n��° ���Ұ� ���°�� ������ �߻�
	bit &= ~(1 << n);
	return bit;
}

//bit�� n��° ������ �� ����( 1�̸� 0, 0�̸� 1��)
int toggleBit(int bit, int n)
{
	bit ^= (1 << n);
	return bit;
}

int calculate(int a, int b)
{
	int added = (a | b); //a�� b�� ������
	int intersection = (a & b); //a�� b�� ������
	int removed = (a & ~b); //a���� b�� �� ������
	int toggle = (a ^ b); //a�� b�� �ϳ��� ���Ե� ����
	return added;
}

//x�� ���Ե� ������ ��
int bitCount(int x)
{
	if (x == 0) return x;
	return x % 2 + bitCount(x / 2);

	/*	
		������ ���
		return __popcnt(x);
	*/

	/*	�������� ���
		int cnt = 0;
		for(int i=0; i < size; i++){
			if(x & (1<<i)) cnt++;
		}
		return cnt;
	*/
}

//bit�� ù��° ���� ��ġ
int firstBit(int bit)
{
	return (bit & -bit);
}

//��� �κ����� ��ȸ�ϱ�
void circuit(int bit)
{
	for (int subset = bit; subset > 0; subset = ((subset - 1) & bit)) {
		//
	}
}