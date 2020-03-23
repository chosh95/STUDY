#include <iostream>
#include <algorithm>
#include <functional>
#include <queue>
#include <vector>
using namespace std;
int N, num;
priority_queue<int, vector<int>, less<int>> maxHeap;
priority_queue<int, vector<int>, greater<int>> minHeap;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	while (N--) {
		cin >> num;
		if (maxHeap.size() == minHeap.size()) {
			maxHeap.push(num);
		}
		else
			minHeap.push(num);

		if (!maxHeap.empty() && !minHeap.empty() && (maxHeap.top() > minHeap.top())) {
			int a = maxHeap.top();
			int b = minHeap.top();
			
			maxHeap.pop();
			maxHeap.push(b);
			minHeap.pop();
			minHeap.push(a);
		}
		cout << maxHeap.top() << "\n";
	}

}