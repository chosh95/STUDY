#include <string>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int solution(int len, int weight, vector<int> truck) {
	int answer = 0; //�ð�
	int curWeight = 0; //���� �ٸ� ���� �ִ� Ʈ�� ����
	int idx = 0; //Ʈ�� �ε���
	queue<int> q; //�ٸ� ���� �ִ� Ʈ�� list
	while (1) {
		answer++;
		if (q.size() == len) { //Ʈ���� �����ϸ� ���� ���ְ� ����
			curWeight -= q.front();
			q.pop();
		}
		if (curWeight + truck[idx] <= weight) { //Ʈ�� �߰��� �� ������ �߰�
			if (idx == truck.size() - 1) { //������ Ʈ���� ��� 
				answer += len;
				break;
			}
			q.push(truck[idx]);
			curWeight += truck[idx];
			idx++;
		}
		else {
			q.push(0); //Ʈ���� �� �� �ø��� 0���� Ʈ�� �о��ֱ�
		}
	}
	return answer;
}

int main()
{
	cout << solution(2, 10, { 7,4,5,6 });
}