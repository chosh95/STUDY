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
	int len = begin.length(); //글자 길이

	while (!q.empty()) {
		string cur = q.front().first; //현재 검사할 단어
		int num = q.front().second; //현재까지 방문 횟수
		q.pop();
		if (cur == target) {
			answer = num;
			break;
		}
		for (int i = 0; i < words.size(); i++) {
			int cnt = 0;
			string next = words[i]; //다음 단어

			if (visit[i]==1) continue; 
			for (int j = 0; j < len; j++) {
				if (cur[j] == next[j]) cnt++;
			}
			if (cnt != len - 1) continue;

			q.push({ next, num + 1 }); //방문 가능시 다음 단어를 q에 추가
			visit[i] = 1;
		}
	}

	return answer;
}

int main()
{
	cout << solution("hit", "cog", {"hot", "dot", "dog", "lot", "log", "cog" });
}