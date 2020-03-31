#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
using namespace std;
int N;
long long dp[21];

string add(string num1, string num2)
{
	long long sum = 0;
	string result;

	while (!num1.empty() || !num2.empty() || sum) {
		if (!num1.empty()) {
			sum += num1.back() - '0';
			num1.pop_back();
		}
		if (!num2.empty()) {
			sum += num2.back() - '0';
			num2.pop_back();
		}
		result.push_back((sum % 10) + '0');
		sum /= 10;
	}
	reverse(result.begin(), result.end());

	return result;
}

string subOne(string num) {
	int sub = num.back() - '0';
	num.pop_back();
	sub -= 1;
	num.push_back(sub + '0');

	return num;
}

void hanoi(int n, int from, int by, int to) {
	if (n == 1)
		cout << from << " " << to << "\n";
	else {
		hanoi(n - 1, from, to, by);
		hanoi(1, from, by, to);
		hanoi(n - 1, by, from, to);
	}
}

int main(void)
{
	cin >> N;
	if (N <= 20)
	{
		dp[1] = 1;
		for (int i = 2; i <= N; i++)
			dp[i] = dp[i - 1] * 2 + 1;
		cout << dp[N] << endl;
		hanoi(N, 1, 2, 3);
	}
	else
	{
		string num = "2";
		for (int i = 0; i < N - 1; i++)
		{
			string temp = add(num, num);
			num = temp;
		}
		cout << subOne(num) << "\n";
	}
	return 0;
}