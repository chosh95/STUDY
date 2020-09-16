#include <algorithm>
#include <vector>
#include <iostream>
#include <math.h>
using namespace std;
vector<int> sum;

int solution(vector<int>& A) {
    sum.resize(A.size() + 1);
    sum[0] = A[0];
    for (int i = 1; i < A.size(); i++) {
        sum[i] = sum[i - 1] + A[i];
    }

    int answer = 987654321;
    int N = A.size() - 1;
    for (int i = 0; i < A.size() - 1; i++) {
        int cur = abs((sum[N] - sum[i]) - sum[i]);
        answer = min(cur, answer);
    }
    return answer;
}

int main()
{
    vector<int> v = { 3,1,2,4,3 };
    cout << solution(v);
}