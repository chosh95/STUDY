#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std; 
int C, N, a, b;

int median()
{
	long long seed = 1983;
	priority_queue<int, vector<int>, less<int>> maxHeap;
	priority_queue<int, vector<int>, greater<int>> minHeap;
	int medSum = 0;
	for (int i = 1; i <= N; i++) {
		if (maxHeap.size() == minHeap.size())
			maxHeap.push(seed);
		else
			minHeap.push(seed);
		if (!minHeap.empty() && !maxHeap.empty() && minHeap.top() < maxHeap.top()) {
			int tmpA = maxHeap.top(), tmpB = minHeap.top();
			maxHeap.pop();
			minHeap.pop();
			maxHeap.push(tmpB);
			minHeap.push(tmpA);
		}
		medSum = (medSum + maxHeap.top()) % 20090711;
		seed = (seed * a + b) % 20090711;
	}
	return medSum;
}

int main()
{
	cin >> C;
	while (C--) {
		cin >> N >> a >> b;
		cout << median() << endl;
	}
}