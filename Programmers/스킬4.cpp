#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int dp1[100001];
int dp2[100001];

int solution(vector<int> sticker)
{
	dp1[0] = sticker[0];
	dp1[1] = sticker[0];
	dp2[0] = 0;
	dp2[1] = sticker[1];
	for (int i = 2; i < sticker.size() - 1; i++) {
		dp1[i] = max(dp1[i - 2] + sticker[i], dp1[i - 1]);
		dp2[i] = max(dp2[i - 2] + sticker[i], dp2[i - 1]);
	}
	int size = sticker.size() - 1;
	int res1 = max(dp1[size - 1], dp1[size - 2]);
	int res2 = max(dp2[size - 1], dp2[size - 2] + sticker[size]);
	return max(res1, res2);
}

int main()
{
	cout << solution({ 14,6,5,11,3,9,2,10 });
}