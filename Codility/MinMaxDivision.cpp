#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isPossible(int mid, int K, vector<int> v) {
    int cnt = 1, sum = 0;
    for (int i = 0; i < v.size(); i++) {
        sum += v[i];
        if (sum > mid) {
            sum = v[i];
            cnt++;
        }
        if (cnt > K) return false;
    }
    return true;
}

int solution(int K, int M, vector<int>& A) {
    int lo = *max_element(A.begin(), A.end());
    int hi = 1000000000;
    
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (isPossible(mid, K, A))
            hi = mid - 1;
        else
            lo = mid + 1;
    }

    return lo;
}

int main()
{
    vector<int> input = { 1,2,3,4,5,4,3,2,1};
    cout << solution(4, 7, input);
}