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

	//int�� ��� string����
	for (int i = 0; i < numbers.size(); i++) 
		str.push_back(to_string(numbers[i]));

	//cmp�� ���� ����
	sort(str.begin(), str.end(), cmp);

	//���ĵ� ���� ��� answer�� ���Ѵ�.
	for (int i = 0; i < str.size(); i++)
		answer += str[i];

	//�Է����� ���� ���� ��� 0�� ���
	if (answer[0] =='0') return "0";

	return answer;
}

int main()
{
	cout << solution({ 30,3,300 });
	cout << solution({ 0,0,0,0 });
}