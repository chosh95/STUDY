#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
using namespace std;

int solution(int X, vector<int> &A) {
    set<int> s;

    for (int i = 0; i < A.size(); i++) {
        if (s.find(A[i]) == s.end())
            s.insert(A[i]);
        if (s.size() == X) return i;
    }
    return -1;
}
