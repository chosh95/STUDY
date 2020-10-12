#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty()) return {};
        vector<int> answer;

        int nr = matrix.size();     if (nr == 0) return answer;
        int nc = matrix[0].size();  if (nc == 0) return answer;

        vector<int> nSteps{ nc, nr - 1 };

        vector<int> dx{ 0,1,0,-1 };
        vector<int> dy{ 1,0,-1,0 };


        int dir = 0;
        int x = 0, y = -1;

        while (nSteps[dir%2]) {
            for (int i = 0; i < nSteps[dir%2]; i++) {
                x += dx[dir];
                y += dy[dir];
                answer.push_back(matrix[x][y]);
            }
            nSteps[dir % 2]--;
            dir = (dir + 1) % 4;
        }

        return answer;
    }
};

int main()
{
    vector<vector<int>> inp = { {1,2,3},{4,5,6},{7,8,9} };
    Solution s;
    vector<int> res = s.spiralOrder(inp);
    for (int x : res)
        cout << x << " ";
}