#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int N;
vector<pair<int, int>> v;

int main()
{
	cin >> N;
	for (int a, b, i = 0; i < N; i++) {
		cin >> a >> b;
		v.push_back({ a,b });
	}
	sort(v.begin(), v.end());

	priority_queue<int,vector<int>,greater<int>> q;
	q.push(v[0].second);
	for (int i = 1; i < N; i++) {
		if (v[i].first < q.top()) { // 현재 강의 종료시간보다 일찍 시작하는 강의일 경우
			q.push(v[i].second); // 강의 추가
		}
		else {
			q.pop();
			q.push(v[i].second);
		}
	}

	cout << q.size();
}