#include <iostream>
#include <string>
#include <vector>
using namespace std;
int p[31];

int solution(int n, vector<int> lost, vector<int> reserve) {
	int answer = n;	

	//��� �л��� ���� �ִٰ� �����ϰ� 1�� �ʱ�ȭ
	for (int i = 0; i <= n; i++) 
		p[i] = 1;

	//������ �ִ� �л��� 1 ����
	for (int i = 0; i < reserve.size(); i++) 
		p[reserve[i]] += 1;

	//���� ���� �л��� 1 ����
	for (int i = 0; i < lost.size(); i++)
		p[lost[i]] -= 1;

	//������ �����ֱ�. �׻� ���� �л����� �����ش�.
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

	for (int i = 1; i <= n; i++) // �� ���� �л� ����
		if (p[i] == 0) answer--;

	return answer;
}

int main()
{
	cout << solution(8, { 5, 6  }, { 4, 5 });
}