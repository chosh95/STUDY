#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <memory.h>
#include <algorithm>
using namespace std;
const int maxNum = 100000001;
bool isPrime[maxNum];
int visit[10];
int cnt;
map<int, int> m;

void eratos() {
	memset(isPrime, true, sizeof(isPrime));
	isPrime[0] = isPrime[1] = false;
	for (int i = 2; i*i < maxNum; i++) {
		if (isPrime[i] == false) continue;
		for (int j = i + i; j < maxNum; j += i)
			isPrime[j] = false;
	}
}

void dfs(string origin, int idx, int cur) {
	if (idx == origin.size()) {
		if (cur == 0) return;
		if (isPrime[cur] && m[cur] == 0) {
			m[cur]++;
			cnt++;
		}
		return;
	}
	dfs(origin, idx + 1, cur);
	for (int i = 0; i < origin.size(); i++) {
		if (visit[i] == true) continue;
		int tmp = cur * 10 + (origin[i]-'0');
		visit[i] = true;
		dfs(origin, idx + 1, tmp);
		visit[i] = false;
	}
}


int solution(string numbers) {
	eratos();
	memset(visit, false, sizeof(visit));

	dfs(numbers, 0,0);

	return cnt;
}

int main()
{
	cout << solution("17");
}