#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

bool isPossible(int mid, vector<int> stones, int k) {
	for (int cnt =0, i = 0; i < stones.size(); i++) {
		if (stones[i] - mid <= 0) cnt++;
		else cnt = 0;
		if (cnt >= k) return false;
	}
	return true;
}
int solution(vector<int> stones, int k) {
	int left = 1;
	int right = 200000001;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (isPossible(mid,stones, k)) 
			left = mid + 1;
		else 
			right = mid - 1;
	}
	return left;
}

int main()
{
	cout << solution({ 2,4,5,3,2,1,4,2,5,1 }, 3);
}