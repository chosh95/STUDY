#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;
map<string, string> m;

vector<string> solution(vector<string> record) {
	vector<string> answer;
	vector<pair<int,string>> tmp;
	for (int i = 0; i < record.size(); i++) {
		string command, id, name;

		if (record[i][0]=='E') {
			int first = record[i].find_first_of(' ');
			int second = record[i].find_last_of(' ');
			id = record[i].substr(first + 1, second - first-1);
			name = record[i].substr(second + 1, record[i].size() - second);
			m[id] = name;
			tmp.push_back({ 1,id });
		}
		else if (record[i][0] == 'L') {
			int first = record[i].find_first_of(' ');
			id = record[i].substr(first + 1, record[i].size()- first);
			tmp.push_back({ 2,id });
		}
		else {
			int first = record[i].find_first_of(' ');
			int second = record[i].find_last_of(' ');
			id = record[i].substr(first + 1, second - first-1);
			name = record[i].substr(second + 1, record[i].size() - second);
			m[id] = name;
		}
	}
	for (int i = 0; i < tmp.size(); i++) {
		int com = tmp[i].first;
		string id = tmp[i].second;
		if (com == 1) {
			answer.push_back(m[id] + "´ÔÀÌ µé¾î¿Ô½À´Ï´Ù.");
		}
		else {
			answer.push_back(m[id] + "´ÔÀÌ ³ª°¬½À´Ï´Ù.");
		}
	}
	return answer;
}

int main()
{
	vector<string> res = solution({"Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan"});
	for (int i = 0; i < res.size(); i++)
		cout << res[i] << endl;
}