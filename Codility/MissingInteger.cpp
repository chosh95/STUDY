#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int solution(vector<int>& A) {
    set<int> s;
    for (int i = 0; i < A.size(); i++) {
        if (A[i] <= 0) continue;
        s.insert(A[i]);
    }

    int res = 1;
    for (auto it = s.begin(); it != s.end(); it++) {
        if (*it != res) return res;
        res++;
    }
    return res;
}

int main()
{
    vector<int> a = {1,2,3};
    cout << solution(a);
}