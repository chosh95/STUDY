#include <string>
#include <iostream>
#include <vector>

using namespace std;

bool solution(vector<string> phone) {
	bool answer = true;
	for (int i = 0; i < phone.size(); i++) {
		for (int j = 0; j < phone.size(); j++) {
			if (i != j && phone[i].find(phone[j]) == 0) {
				answer = false;
				return answer;
			}
		}
	}
	return answer;
}

int main()
{
	vector<string> v = {"119","119312","143"};
	cout << solution(v);
}