#include <string>
#include <iostream>
#include <vector>

using namespace std;

int joyStick(char cur) {
	if (cur <= 'N')
		return cur - 'A';
	else
		return 'Z' - cur + 1;
}

int solution(string name) {
	int answer = 0;
	string tmp(name.size(), 'A');
	int cur = 0, left, right;

	while (name != tmp) {
		answer += joyStick(name[cur]);
		name[cur] = 'A';
		if (name == tmp) break;
		for (int i = 1; i <= name.size() / 2; i++) {
			right = cur + i;
			left = cur - i;
			if (right >= name.size()) right -= name.size();
			if (left < 0) left += name.size();
			if (name[right] != 'A') {
				answer += i;
				cur = right;
				break;
			}
			else if (name[left] != 'A') {
				answer += i;
				cur = left;
				break;
			}
		}
	}

	return answer;
}

int main()
{
	cout << solution("JEROEN");
}