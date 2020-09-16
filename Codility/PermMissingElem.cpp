#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int solution(vector<int>& A) {
    
    sort(A.begin(), A.end());
    for (int i = 0; i < A.size(); i++) {
        if (A[i] != i + 1) return i + 1;
    }
    return A.size() + 1;
}
