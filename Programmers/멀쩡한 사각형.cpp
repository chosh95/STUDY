#include <iostream>
#include <algorithm>

using namespace std;
int gcdFun(int a, int b) {
	if (b == 0) return a;
	return gcdFun(b, a % b);
}

long long solution(int w, int h) {
	long long sum = (long long)w * (long long)h;
	int gcd = gcdFun(w, h);

	long long answer = sum - ((w / gcd) + (h / gcd) - 1) * gcd;
	return answer;
}

int main()
{
	cout << solution(8, 12);
}