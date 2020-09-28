#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int>& A) {
    if (A.empty()) return -1;

    map<int, int> m;
    for (int i = 0; i < A.size(); i++) 
        m[A[i]]++;

    int maxNum = 0, maxKey = 0;
    for (auto it : m) {
        if (it.second > maxNum) {
            maxNum = it.second;
            maxKey = it.first;
        }
    }
    
    if (maxNum <= A.size() / 2) return -1;
    for (int i = 0; i < A.size(); i++) {
        if (A[i] == maxKey) return i;
    }
}

int main() {
    vector<int> input = { 3, 4, 3, 2, 3, -1, 3, 3 };
    cout << solution(input);
}
