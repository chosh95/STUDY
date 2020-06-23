#include <iostream>
#include <queue>
#include <map>
#include <algorithm>
#include <string>
using namespace std;
int N;
int res;
map<char, int> m;

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		int cur = 1;
		for (int j = str.size() - 1; j >= 0; j--) {
			m[str[j]] += cur;
			cur *= 10;
		}
	}
	priority_queue<int> q;
	map<char, int>::iterator iter;
	for (iter = m.begin(); iter != m.end(); iter++)
		q.push(iter->second);

	int count = 9;
	while (!q.empty()) {
		res += q.top() * count;
		q.pop();
		count--;
	}
	
	cout << res;
}