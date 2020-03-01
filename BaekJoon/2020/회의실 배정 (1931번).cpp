#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N;
vector<pair<int,int>> p;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int start, end, i = 0; i < N; i++) {
		cin >> start >> end;
		p.push_back({ end, start });
	}
	sort(p.begin(),p.end());

	int teamCnt = 1;
	int curEnd = p[0].first;

	for (int i = 1; i < N; i++) {
		if (p[i].second < curEnd) continue;
		curEnd = p[i].first;
		teamCnt++;
	}

	cout << teamCnt;
}