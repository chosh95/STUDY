#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;

    map<string, int> m;

    string tmp = "";
    for (int i = 1; i < s.size()-1; i++) {
        if (s[i] == '{') continue;
        if (s[i - 1] == '}' && s[i] == ',') continue;
        if (s[i] == ',' || s[i] == '}') {
            m[tmp]++;
            tmp.clear();
        }
        else {
            tmp += s[i];
        }
    }

    int idx = 1;
    while(!m.empty()){
        for (auto it : m) {
            if (it.second == idx) {
                answer.push_back(stoi(it.first));
                m.erase(it.first);
                idx++;
                break;
            }
        }
    }

    reverse(answer.begin(), answer.end());
    return answer;
}

int main()
{
    vector<int> res = solution("{{2},{2,1},{2,1,3},{2,1,3,4}}");
    for (int cur : res) {
        cout << cur << " ";
    }
}