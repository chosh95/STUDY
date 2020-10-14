#include <iostream>
#include <queue>
#include <algorithm>
#include <map>
using namespace std;

class Solution {
public:
    int brokenCalc(int X, int Y) {
        if (Y <= X)
            return X - Y;
        if (Y % 2 == 0) 
            return brokenCalc(X, Y / 2) + 1;
        return 1 + brokenCalc(X, Y + 1);
    }
};

int main()
{
    Solution s;
    cout << s.brokenCalc(1, 1024);
}