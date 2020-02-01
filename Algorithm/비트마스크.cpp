#include <iostream>
#include <intrin.h> //__popcnt 포함 헤더
using namespace std;

//n개의 1로 꽉찬 비트 반환
int fullBit(int n)
{
	return (1 << n) - 1;
}

//bit의 n번째 위치에 원소를 추가
int insertBit(int bit, int n)
{
	bit |= (1 << n);
	return bit;
}

//bit의 n번째 위치에 원소가 포함되어있는가
bool isContain(int bit, int n)
{
	bool res = (bit & (1 << n));
	return res;
}

//bit의 n번째 위치의 원소를 삭제
int removeBit(int bit, int n)
{
	//bit -= (1<<n)은 bit에 n번째 원소가 없는경우 오류가 발생
	bit &= ~(1 << n);
	return bit;
}

//bit의 n번째 원소의 값 변경( 1이면 0, 0이면 1로)
int toggleBit(int bit, int n)
{
	bit ^= (1 << n);
	return bit;
}

int calculate(int a, int b)
{
	int added = (a | b); //a와 b의 합집합
	int intersection = (a & b); //a와 b의 교집합
	int removed = (a & ~b); //a에서 b를 뺀 차집합
	int toggle = (a ^ b); //a와 b중 하나만 포함된 원소
	return added;
}

//x에 포함된 원소의 수
int bitCount(int x)
{
	if (x == 0) return x;
	return x % 2 + bitCount(x / 2);

	/*	
		간편한 방법
		return __popcnt(x);
	*/

	/*	원시적인 방법
		int cnt = 0;
		for(int i=0; i < size; i++){
			if(x & (1<<i)) cnt++;
		}
		return cnt;
	*/
}

//bit의 첫번째 원소 위치
int firstBit(int bit)
{
	return (bit & -bit);
}

//모든 부분집합 순회하기
void circuit(int bit)
{
	for (int subset = bit; subset > 0; subset = ((subset - 1) & bit)) {
		//
	}
}