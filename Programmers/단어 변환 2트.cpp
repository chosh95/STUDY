#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
using namespace std;

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    map<string, int> m;

    queue<pair<string, int>> q;
    q.push({ begin,0 });
    m[begin] = 1;

    while (!q.empty()) {
        string cur = q.front().first;
        int cnt = q.front().second;
        q.pop();

        if (cur == target) {
            answer = cnt;
            break;
        }

        for (int i = 0; i < words.size(); i++) {
            string next = words[i];
            if (m[next] == 1) continue; // �湮�� ���ڴ� continue

            int diff = 0; //�ѱ��ڸ� ���̳����� Ȯ��
            for (int j = 0; j < cur.size(); j++)
                if (cur[j] != next[j]) diff++;
            if (diff != 1) continue;

            q.push({ next,cnt + 1 });
            m[next] = 1;
        }
    }

    return answer;
}

int main()
{
	cout << solution("hit", "cog", { "hot", "dog", "dog", "lot", "log","cog" });
}