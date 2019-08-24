#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <queue>
using namespace std;
int N, K;
string res = "0";

void bfs()
{
	queue<string> q;
	q.push(to_string(N));

	for (int i = 0; i < K; i++) {
		int qsize = q.size();
		set<string> visit;
		for (int j = 0; j < qsize; j++) {
			string str = q.front();
			q.pop();
			if (visit.count(str)) continue;
			visit.insert(str);
			for (int k = 0; k < str.size() - 1; k++) {
				for (int l = k + 1; l < str.size(); l++) {
					if (k > 0 || str[l] != '0') {
						swap(str[k], str[l]);
						q.push(str);
						swap(str[k], str[l]);
					}
				}
			}
		}
	}
	while (!q.empty()) {
		res = max(res, q.front());
		q.pop();
	}
}

int main()
{
	cin >> N >> K;
	bfs();
	if (res[0] == '0') cout << "-1";
	else cout << res;
}