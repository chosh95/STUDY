#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int H, W;
int height[501];

int main()
{
	cin >> H >> W;
	for (int index = 1; index <= W; index++) 
		cin >> height[index];

	int rainSum = 0;

	for (int cur = 2; cur <= W - 1; cur++) {
		for (int curHeight = H; curHeight > height[cur]; curHeight--){
			bool leftCheck = false, rightCheck = false;

			for (int left = 1; left < cur; left++) {
				if (height[left] >= curHeight) {
					leftCheck = true;
					break;
				}
			}

			for (int right = W; right > cur; right--) {
				if (height[right] >= curHeight) {
					rightCheck = true;
					break;
				}
			}

			if (leftCheck && rightCheck) {
				rainSum += (curHeight - height[cur]);
				break;
			}

		}
	}

	cout << rainSum;
}