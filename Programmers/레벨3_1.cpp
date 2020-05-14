#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int crewTime[2020];

string solution(int n, int t, int m, vector<string> timetable) {
	string answer = "";
	sort(timetable.begin(), timetable.end());
	for (int i = 0; i < timetable.size(); i++) {
		int h = stoi(timetable[i].substr(0, 2));
		int m = stoi(timetable[i].substr(3, 2));
		crewTime[i] = h * 60 + m;
	}

	int res = 0;
	int bus = 540;
	int crewNum = timetable.size();
	int idx = 0;

	for (int i = 0; i < n; i++) {
		int tmpM = 0;
		for(int j = idx;j<crewNum;j++){
			if (crewTime[idx] <= bus) {
				idx++;
				tmpM++;
			}
			if (tmpM == m) break;
		}

		if (i == n - 1) {
			if (tmpM == m) {
				res = crewTime[idx-1]-1;
			}
			else {
				res = bus;
			}
		}
		bus += t;
		if (bus>= 24*60) break;
	}

	int tmpH = res / 60;
	if (tmpH < 10) answer += "0" + to_string(tmpH);
	else answer += to_string(tmpH);
	int tmpM = res % 60;
	if (tmpM < 10) answer += ":0" + to_string(tmpM);
	else answer += ":" + to_string(tmpM);
	return answer;
}

int main()
{
	cout << solution(1, 1, 5, { "08:00","08:01","08:02","08:03" });
}