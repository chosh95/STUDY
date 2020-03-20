#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int N;

bool isPrime(int x) {
	for (int i = 2; i * i <= x; i++) 
		if (x % i == 0) return false;
	
	return true;
}
void dfs(int idx, int sum) { //idx : 자리수, sum : 만든 수
	if (idx == N) {
		cout << sum << "\n";
		return;
	}
	
	for (int i = 1; i <= 9; i += 2) 
		if (isPrime(sum * 10 + i)) 
			dfs(idx + 1, sum * 10 + i);
}

int main()
{
	cin >> N;
	
	dfs(1, 2); // 1의 자리에 올 수 있는 소수들
	dfs(1, 3); // 2, 3, 5, 7을 차례로 넣는다.
	dfs(1, 5);
	dfs(1, 7); 

	return 0;
}