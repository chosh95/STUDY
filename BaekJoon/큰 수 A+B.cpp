#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string addbig(string num1, string num2)
{
	long long sum = 0;
	string ret;
	while (!num1.empty() || !num2.empty() || sum) {
		if (!num1.empty()) {
			sum += num1.back() - '0';
			num1.pop_back();
		}
		if (!num2.empty()) {
			sum += num2.back() - '0';
			num2.pop_back();
		}
		ret.push_back((sum % 10) + '0');
		sum /= 10;
	}
	reverse(ret.begin(), ret.end());
	return ret;
}
int main()
{
	string A, B;
	cin >> A >> B;
	cout<<addbig(A, B);
}