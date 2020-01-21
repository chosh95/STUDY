#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <stack>
using namespace std;
int N, K;
int p[500001];
deque<int> q;

int main()
{
	cin >> N >> K;
	int len = N - K;
	for (int i = 1; i <= N; i++)
		scanf(" %1d", &p[i]);
	q.push_front(p[1]);
	for(int i=2;i<=N;i++){
		while (!q.empty() && q.back() < p[i] && K > 0) {
			q.pop_back();
			K--;
		}
		q.push_back(p[i]);
	}
	while (K > 0) {
		q.pop_back();
		K--;
	}

	for (int i = 0; i < len; i++) {
		cout << q.front();
		q.pop_front();
	}
	
}