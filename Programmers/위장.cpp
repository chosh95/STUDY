#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

int solution(vector<vector<string>> clothes) {
	int answer = 1;
	map<string, int> m;
	for (int i = 0; i < clothes.size(); i++) {
		m[clothes[i][1]]++;
	}
	for (auto idx = m.begin(); idx != m.end();idx++) {
		answer *= (idx->second+1);
	}
	return answer - 1;
}

int main()
{
	cout << solution({ {"crow_mask", "face"},{"blue_sunglasses", "face"},{"smoky_makeup", "face" } });
}