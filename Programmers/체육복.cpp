#include <iostream>
#include <string>
#include <vector>
using namespace std;
int p[31];

int solution(int n, vector<int> lost, vector<int> reserve) {
	int answer = n;	

	//모든 학생이 옷이 있다고 가정하고 1로 초기화
	for (int i = 0; i <= n; i++) 
		p[i] = 1;

	//여유분 있는 학생은 1 증가
	for (int i = 0; i < reserve.size(); i++) 
		p[reserve[i]] += 1;

	//도난 당한 학생은 1 감소
	for (int i = 0; i < lost.size(); i++)
		p[lost[i]] -= 1;

	//여유분 나눠주기. 항상 왼쪽 학생부터 나눠준다.
	for (int i = 1; i <= n; i++) {
		if (p[i] == 1 || p[i] == 0) continue;
		if (p[i - 1] == 0) {
			p[i - 1] = p[i] = 1;
			continue;
		}
		else if (p[i + 1] == 0) {
			p[i + 1] = p[i] = 1;
			continue;
		}
	}

	for (int i = 1; i <= n; i++) // 옷 없는 학생 빼기
		if (p[i] == 0) answer--;

	return answer;
}

int main()
{
	cout << solution(8, { 5, 6  }, { 4, 5 });
}