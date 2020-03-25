#include <string>
#include <iostream>
#include <vector>

using namespace std;

string solution(int a, int b) {
	string answer = "";
	int month[13] = { 0, 31, 29, 31,30,31,30,31,31,30,31,30,31 };
	vector<string> res = { "THU", "FRI","SAT","SUN","MON","TUE","WED" };
	int day = b;
	for (int i = 1; i < a; i++)
		day += month[i];
	day %= 7;
	answer = res[day];
	return answer;
}

int main()
{
	string tmp = solution(1, 1);
	cout << tmp;
}