#include <iostream>
#include <algorithm>
#include <math.h>
#include <queue>
#include <vector>
#include <map>
using namespace std;
long long K, N;
long long p[101];
priority_queue<long long,vector<long long>,greater<long long>> q;
map<long long, int>  m;

int main()
{
	
	cin >> K >> N;	
	for (int i = 1; i <= K; i++) {
		cin >> p[i];
		q.push(p[i]);
		m[p[i]] = 1;
	}

	long long maximum = p[K]; //q속에 있는 최대값
	int idx = 0;

	while(!q.empty()){
		long long cur = q.top();
		q.pop();
		idx++;

		if (idx == N) { //N번째 값 출력
			cout << cur;
			break;
		}

		for (int i = 1; i <= K; i++) {
			if (q.size() + idx > N && cur * p[i] > maximum) break; //종료조건, N보다 많은 값이 있을 때 최대값보다 큰 값이 들어오면 종료
			if (m[cur * p[i]] == 1) continue; //중복 제거
			m[cur * p[i]] = 1;
			q.push(cur * p[i]); 
			maximum = max(maximum, cur * p[i]);
		}
	}
}