#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
	string answer = "";
	map<string, int> m;
	for (int i = 0; i < participant.size(); i++) 
		m[participant[i]]++;
	for (int i = 0; i < completion.size(); i++)
		m[completion[i]]--;
	for (int i = 0; i < participant.size(); i++)
		if (m[participant[i]] != 0) answer = participant[i];
	return answer;
}

int main()
{
	vector<string> participant = { "mislav", "stanko", "mislav", "ana" };
	vector<string> completion = { "stanko", "ana", "mislav" };
	string res = solution(participant, completion);
	cout << res;
}