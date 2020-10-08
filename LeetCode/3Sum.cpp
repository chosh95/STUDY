#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> answer;
        sort(nums.begin(), nums.end());
        int n = nums.size();

        int left, right;
        for (int i = 0; i < n-2; i++) {

            left = i + 1;
            right = n - 1;

            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];

                if (sum == 0) {
                    answer.push_back(vector<int>{ nums[i],nums[left],nums[right] });
                    while (left < right && nums[left] == nums[left + 1]) left++; // 중복 값 제거
                    while (left < right && nums[right] == nums[right - 1]) right--; // 중복 값 제거
                    left++; // 다음 숫자 쌍 검사
                    right--;
                }
                else if (sum < 0) {
                    left++;
                }
                else {
                    right--;
                }
            }

            while (i < n-2 && nums[i] == nums[i + 1]) i++; // 중복되는 값 제거
        }

        return answer;
    }

};

int main()
{
    vector<int> input = { -1, 0, 1, 2, -2 };

    Solution s;
    vector<vector<int>> res = s.threeSum(input);

    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < 3; j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
}