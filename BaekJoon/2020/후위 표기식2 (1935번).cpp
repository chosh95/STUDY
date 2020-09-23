#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;
int N;
double number[26];
string origin;
stack<double> operand;

int main()
{
	cin >> N;
	cin >> origin;
	for (int numberIndex = 0; numberIndex < N; numberIndex++) 
		cin >> number[numberIndex];
	
	for (int originIndex = 0; originIndex < origin.size(); originIndex++) {
		if (origin[originIndex] >= 'A' && origin[originIndex] <= 'Z')
			operand.push(number[origin[originIndex] - 'A']);
		else {
			double lastNum = operand.top();
			operand.pop();
			double firstNum = operand.top();
			operand.pop();
			if (origin[originIndex] == '+')
				operand.push(firstNum + lastNum);
			else if (origin[originIndex] == '-')
				operand.push(firstNum - lastNum);
			else if (origin[originIndex] == '*')
				operand.push(firstNum * lastNum);
			else
				operand.push(firstNum / lastNum);
		}
	}

	cout << fixed;
	cout.precision(2);
	cout << operand.top();
}