#include <string>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int visit[51];
int solution(string begin, string target, vector<string> words) {
	int answer = 0;
	queue<pair<string, int>> q;
	q.push({ begin, 0 });
	int len = begin.length(); //���� ����

	while (!q.empty()) {
		string cur = q.front().first; //���� �˻��� �ܾ�
		int num = q.front().second; //������� �湮 Ƚ��
		q.pop();
		if (cur == target) {
			answer = num;
			break;
		}
		for (int i = 0; i < words.size(); i++) {
			int cnt = 0;
			string next = words[i]; //���� �ܾ�

			if (visit[i]==1) continue; 
			for (int j = 0; j < len; j++) {
				if (cur[j] == next[j]) cnt++;
			}
			if (cnt != len - 1) continue;

			q.push({ next, num + 1 }); //�湮 ���ɽ� ���� �ܾ q�� �߰�
			visit[i] = 1;
		}
	}

	return answer;
}

int main()
{
	cout << solution("hit", "cog", {"hot", "dot", "dog", "lot", "log", "cog" });
}