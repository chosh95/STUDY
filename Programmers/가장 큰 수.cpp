#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
vector<string> str;

bool cmp(string a, string b) {
	if (a + b <= b + a)
		return false;
	return true;
}

string solution(vector<int> numbers) {
	string answer = "";

	//int를 모두 string으로
	for (int i = 0; i < numbers.size(); i++) 
		str.push_back(to_string(numbers[i]));

	//cmp에 따라 정렬
	sort(str.begin(), str.end(), cmp);

	//정렬된 수를 모두 answer에 합한다.
	for (int i = 0; i < str.size(); i++)
		answer += str[i];

	//입력으로 들어온 수가 모두 0인 경우
	if (answer[0] =='0') return "0";

	return answer;
}

int main()
{
	cout << solution({ 30,3,300 });
	cout << solution({ 0,0,0,0 });
}