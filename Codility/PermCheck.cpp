#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int solution(vector<int>& A) {
    
    set<int> s;
    int curMax = 0;
    for (int i = 0; i < A.size(); i++) {
        if (s.find(A[i]) != s.end()) return 0;
        s.insert(A[i]);
        curMax = max(curMax, A[i]);
    }

    if (s.size() < curMax)
        return 0;
    return 1;
}

int main()
{
    vector<int> a = {3,2, 1,1,1 };
    cout << solution(a);
}
