#include <string>
#include <iostream>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
	int answer = 0;
	
	for (int i = 0; i < skill_trees.size(); i++) {
		vector<int> pos;
		bool isTrue = true;
		for (int j = 0; j < skill.size(); j++)
			pos.push_back(skill_trees[i].find(skill[j]));
		

		for (int k = 0; k < pos.size() - 1; k++) {
			if ((pos[k] > pos[k + 1] && pos[k+1] != -1) || (pos[k]==-1 && pos[k+1] != -1)) {
				isTrue = false;
				break;
			}
		}
		if (isTrue) answer++;
	}


	return answer;
}

int main()
{
	cout << solution("CBD", { "BACDE", "CBADF", "AECB", "BDA" });
}